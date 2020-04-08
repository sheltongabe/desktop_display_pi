import time

import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

##
# @class	HumitureSensor
# Represent a Humidity sensor and find its value in a thread
class HumitureSensor:
    HUMIDITY_MIN = 10
    HUMIDITY_MAX = 30

    def __init__(self):
        self.NAME = 'humiture'
        self._LOOP_DELAY = 0.005
        self._SENSOR_PIN = 17
        self._running = True

    ## Thread loop
    def run(self):
        while self._running:
            result = self.getHumidity()
            if result:
                humidity, temperature = result
                self._data = humidity

            time.sleep(self._LOOP_DELAY)


    # Following code used from Sunfounder programmer DREAM provided under GPL License
    # link: https://github.com/sunfounder/SunFounder_SensorKit_for_RPi2/blob/master/Python/28_humiture.py
    def getHumidity(self):
        MAX_UNCHANGE_COUNT = 100

        STATE_INIT_PULL_DOWN = 1
        STATE_INIT_PULL_UP = 2
        STATE_DATA_FIRST_PULL_DOWN = 3
        STATE_DATA_PULL_UP = 4
        STATE_DATA_PULL_DOWN = 5

        GPIO.setup(self._SENSOR_PIN, GPIO.OUT)
        GPIO.output(self._SENSOR_PIN, GPIO.HIGH)
        time.sleep(0.05)
        GPIO.output(self._SENSOR_PIN, GPIO.LOW)
        time.sleep(0.02)
        GPIO.setup(self._SENSOR_PIN, GPIO.IN, GPIO.PUD_UP)

        unchanged_count = 0
        last = -1
        data = []
        while True:
            current = GPIO.input(self._SENSOR_PIN)
            data.append(current)
            if last != current:
                unchanged_count = 0
                last = current
            else:
                unchanged_count += 1
                if unchanged_count > MAX_UNCHANGE_COUNT:
                    break

        state = STATE_INIT_PULL_DOWN

        lengths = []
        current_length = 0

        for current in data:
            current_length += 1

            if state == STATE_INIT_PULL_DOWN:
                if current == GPIO.LOW:
                    state = STATE_INIT_PULL_UP
                else:
                    continue
            if state == STATE_INIT_PULL_UP:
                if current == GPIO.HIGH:
                    state = STATE_DATA_FIRST_PULL_DOWN
                else:
                    continue
            if state == STATE_DATA_FIRST_PULL_DOWN:
                if current == GPIO.LOW:
                    state = STATE_DATA_PULL_UP
                else:
                    continue
            if state == STATE_DATA_PULL_UP:
                if current == GPIO.HIGH:
                    current_length = 0
                    state = STATE_DATA_PULL_DOWN
                else:
                    continue
            if state == STATE_DATA_PULL_DOWN:
                if current == GPIO.LOW:
                    lengths.append(current_length)
                    state = STATE_DATA_PULL_UP
                else:
                    continue
        if len(lengths) != 40:
            #print ("Data not good, skip")
            return False

        shortest_pull_up = min(lengths)
        longest_pull_up = max(lengths)
        halfway = (longest_pull_up + shortest_pull_up) / 2
        bits = []
        the_bytes = []
        byte = 0

        for length in lengths:
            bit = 0
            if length > halfway:
                bit = 1
            bits.append(bit)
        #print ("bits: %s, length: %d" % (bits, len(bits)))
        for i in range(0, len(bits)):
            byte = byte << 1
            if (bits[i]):
                byte = byte | 1
            else:
                byte = byte | 0
            if ((i + 1) % 8 == 0):
                the_bytes.append(byte)
                byte = 0
        #print (the_bytes)
        checksum = (the_bytes[0] + the_bytes[1] + the_bytes[2] + the_bytes[3]) & 0xFF
        if the_bytes[4] != checksum:
            #print ("Data not good, skip")
            return False

        return the_bytes[0], the_bytes[2]