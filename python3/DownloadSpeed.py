import threading

class DownloadSpeed(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self._downloadSpeed = 5.2

    def run(self):
        print("Reading Download Speed")

    def getSpeed(self):
        return self._downloadSpeed
