import threading

## Thread to get the external temperature
class ExternalTemperature(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self._temperature = 12

    def run(self):
        print('Reading External Temperature')

    def getTemperature(self):
        return self._temperature
