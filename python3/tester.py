import time, threading
from pi import PI

#variable for if the main loop should run
shouldRun = True

#import requests and shutil
try:
    import requests, shutil
except ImportError:
    print("Please run setup.sh to install requests")
    shouldRun = False

#import bs4 and if unsuccessful set flag to exit
try:
    from bs4 import BeautifulSoup
except ImportError:
    print("Please run setup.sh to install beautiful soup 4")
    shouldRun = False

import os

#interval of 30 sec
INTERVAL = 60

# Timeout for reading the sensors
SENSOR_TIMEOUT = 15

#URL of test download file
DOWNLOAD_URL = "http://mirror.steadfast.net/cygwin/x86_64/setup.ini"

#URL for weather file
WEATHER_URL = "https://weather.com/weather/today/l/46229:4:US"

#name for file to be saved as
FILE_NAME = "file"

#Size of file in Megabits
FILE_SIZE = 16 * 8

#get the current time
currentTime = lambda: int(round(time.time() * 1000))

#function for testing the downloadSpeed
def downloadSpeed(ret):
    """
    a file that marks a start time and downloads a file.
    after finishing downloading the file it marks the end time
    and calculates the download speed
    returns the download speed in mb/s
    """
    #measure the download speed
    #variable for start time
    startTime = currentTime()

    try:
        #open and download the file
        r = requests.get(DOWNLOAD_URL, stream = True, timeout=0.5)

        #read the connection and write it to a file
        with open (FILE_NAME, 'wb') as file:
            shutil.copyfileobj(r.raw, file)

        #store the change in time in seconds
        deltaTime = (currentTime() - startTime) / 1000.0

        #delete the file
        os.remove(FILE_NAME)

        #download speed = FILE_SIZE / deltaTime -> Kb/Sec
        ret[0] = float(FILE_SIZE) / deltaTime
    except:
        ret[0] = "-"
        print("ERROR: error getting download speed.")

def temperature(ret):
    """
        function that takes connects and downloads an html page from weather.com
        it will then use beautiful soup to get the temperature, then deleting the
        file and returning the temperature as a float
    """
    try:
        #download a file for weather.com with the passed zip-code and country
        r = requests.get(WEATHER_URL, stream = True, timeout=0.5)
        with open(FILE_NAME + ".html", 'w') as file:
            file.write(r.text)

        #create a soup from the weather.com html file
        with open(FILE_NAME + ".html") as fp:
            soup = BeautifulSoup(fp, "html.parser")

        #grab the temperature
        soup = soup.find(attrs = {"class": "today_nowcard-temp"}).span.contents[0]

        #delete the file
        os.remove(FILE_NAME + ".html")

        ret[0] = float(soup)
    except:
        ret[0] = "-"
        print("ERROR: error getting temperature")

def main():
    pi = PI()
    while shouldRun:
        #create variables
        speed = ['-']
        temp = ['-']

        #get the download speed on a seperate thread
        downloadThread = threading.Thread(target=downloadSpeed, args=[speed])
        downloadThread.start()

        #get the temperature
        temperatureThread = threading.Thread(target=temperature, args=[temp])
        temperatureThread.start()

        # Loop and allow the threads to execute till completion or timeout
        startTime = currentTime()
        while ((currentTime() - startTime) / 1000.0 < SENSOR_TIMEOUT) and (temperatureThread.is_alive() or downloadThread.is_alive()):
            time.sleep(0.5)

        #get the internal temp in degrees celsius
        tempIntCel = 0.0
        if pi.valid_import():
            tempIntCel = pi.getTemp()

        #setup the text to write to the file
        text = ""

        #if download speed is valid
        if not downloadThread.is_alive() and speed[0] != "-":
            #output speed
            text += str(round(speed[0], 2)) + "\n"
        else:
            #output a hyphen
            text += speed[0] + "\n"

        #if temp was valid
        if not temperatureThread.is_alive() and temp[0] != "-":
            #output tempFarenheit
            text += str(round(temp[0])) + "\n"

            #output tempCelsius
            text += str(round((5.0 / 9.0) * (temp[0] - 32), 1)) + "\n"
        else:
            #if temp failed write two hyphens for temps
            text += temp[0] + "\n"
            text += temp[0] + "\n"

        #if the pi had valid imports
        if pi.valid_import():
            text += str(round(tempIntCel, 1)) + "\n"
            tempIntFar = (9.0 / 5.0) * tempIntCel + 32
            text += str(round(tempIntFar)) + "\n"
        else:
            text += "-\n-\n"

        #open a file to write to
        file = open("data.txt", "w")
        file.write(text)
        file.close()

        time.sleep(INTERVAL)

if __name__ == "__main__":
    main()
