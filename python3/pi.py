VALID_IMPORT = True
try:
    import PCF8591 as ADC
    import RPi.GPIO as GPIO
    from humiture_sensor import HumitureSensor
    import time, math
except ImportError:
    print("error installing Raspberry Pi Sensor Libraries, run setup.sh to install")
    VALID_IMPORT = False

class PI:
    """pi.py
        class for handling communication with the rasperry pi
    """

    def __init__(self):
        """ pi.init()
            constructor to initialize class
        """
        self._valid_import = VALID_IMPORT
        
        #setup constants
        self._DO = 17
        if(self._valid_import):
            GPIO.setmode(GPIO.BCM)
            ADC.setup(0x48)
            GPIO.setup(self._DO, GPIO.IN)
            self._humiture = HumitureSensor()
    
    def valid_import(self):
        return self._valid_import

    def getTemp(self):
        """ pi.getTemp()
            method that returns the temperature 
            returned by rasperrypi.
        """
        if(self.valid_import()):
            result = self._humiture.getHumidity()
            if result:
                humidity, temperature = result
                return temperature
            # return self.analogToTemp(ADC.read(0))
        else:
            return None
        return None

    def analogToTemp(self, analog):
        Vr = 5 * float(analog) / 255
        Rt = 10000 * Vr / (5 - Vr)
        temp = 1 / (((math.log(Rt / 10000)) / 3950) + (1 / (273.15 + 25)))
        temp -= 273.15

        return temp
