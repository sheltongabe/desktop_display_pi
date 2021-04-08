import time, threading
from ExternalTemperature import ExternalTemperature
from DownloadSpeed import DownloadSpeed

LOOP_SLEEP = 1
LOOP_INTERVAL = 10

class Main(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        
        self._sensorTempThread = None
        self._externalTempThread = None
        self._downloadSpeedThread = None

    def run(self):
        # Create & execute the following threads
        # Read Sensor Temperature
        self._sensorTempThread = SensorTemperature()
        self._sensorTempThread.start()
        
        # Read External Temperature
        self._externalTempThread = ExternalTemperature()
        self._externalTempThread.start()

        # Read Dowload Speed
        self._downloadSpeedThread = DownloadSpeed()
        self._downloadSpeedThread.start()
        
        # Join Threads up
        self._externalTempThread.join()
        self._downloadSpeedThread.join()
        self._sensorTempThread.join()

        # Read data from threads
        sensorTemperature = self._sensorTempThread.getTemperature()
        externalTemperature = self._externalTempThread.getTemperature()
        downloadSpeed = self._downloadSpeedThread.getSpeed()

        # Output the data to a file
        print("External Temperature: {}".format(externalTemperature))
        print("Download Speed: {}".format(downloadSpeed))

## Main Loop
def main():
    lastTime = time.time()
    running = True
    while running:
        if time.time() - lastTime > LOOP_INTERVAL:
            mainThread = Main()
            mainThread.start()
            mainThread.join(10)

            lastTime = time.time()

        time.sleep(LOOP_SLEEP)


if __name__ == '__main__':
    main()
