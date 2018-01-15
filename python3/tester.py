import time;
import requests, shutil;
from bs4 import BeautifulSoup;
import os;

#interval of 30 sec
INTERVAL = 60;

#URL of test download file
DOWNLOAD_URL = "http://mirror.steadfast.net/cygwin/x86_64/setup.ini";

#URL for weather file
WEATHER_URL = "https://weather.com/weather/today/l/46229:4:US";

#name for file to be saved as
FILE_NAME = "file";

#Size of file in Megabits
FILE_SIZE = 12 * 8;
#lambda for current time in milliseconds

currentTime = lambda: int(round(time.time() * 1000));

#function for testing the downloadSpeed
def downloadSpeed():
    """
    a file that marks a start time and downloads a file.
    after finishing downloading the file it marks the end time
    and calculates the download speed
    returns the download speed in mb/s
    """
    #measure the download speed
    #variable for start time
    startTime = currentTime();

    #open and download the file
    r = requests.get(DOWNLOAD_URL, stream = True);
    
    #read the connection and write it to a file
    with open (FILE_NAME, 'wb') as file:
       shutil.copyfileobj(r.raw, file);

    #store the change in time in seconds
    deltaTime = (currentTime() - startTime) / 1000.0;

    #delete the file
    os.remove(FILE_NAME);

    #download speed = FILE_SIZE / deltaTime -> Kb/Sec
    return float(FILE_SIZE) / deltaTime;

def temperature():
    """
        function that takes connects and downloads an html page from weather.com
        it will then use beautiful soup to get the temperature, then deleting the
        file and returning the temperature as a float
    """
    #download a file for weather.com with the passed zip-code and country
    r = requests.get(WEATHER_URL, stream = True);
    with open(FILE_NAME + ".html", 'w') as file:
        file.write(r.text);

    #create a soup from the weather.com html file
    with open(FILE_NAME + ".html") as fp:
        soup = BeautifulSoup(fp, "html.parser");

    #grab the temperature
    soup = soup.find(attrs = {"class": "today_nowcard-temp"}).span.contents[0];

    #delete the file
    os.remove(FILE_NAME + ".html");

    return float(soup);

def main():
    while(True):

        speed = downloadSpeed();
        temp = temperature();

        #setup the text to write to the file
        text = "";

        #output speed
        text += str(round(speed, 2)) + "\n";

        #output tempFarenheit
        text += str(round(temp, 2)) + "\n";

        #output tempCelsius
        text += str(round((5.0 / 9.0) * (temp - 32), 1)) + "\n";

        #open a file to write to
        file = open("data.txt", "w");
        file.write(text);
        file.close();

        time.sleep(INTERVAL);

if(__name__ == "__main__"):
    main();
