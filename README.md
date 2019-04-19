# desktop_display_pi

Desktop Display for Rasberry Pi 3 with Qt5

An application designed to serve as a basic display for a desktop
with simple information such as Time, Date, Weather, Internet Speed

The Python code writes the internet speed to a file that is then read by the
C++ code and fed into the gui.

Requirements:
    Qt5 - for gui

Python:
    -Python 3.5 or earlier
    -Modules: speedtest

## Sensors Layout

Two Sensors are required: PCF8591 and Thermistor (both Sunfoundry)

* Both sensors connect to 3.3V Power supply
* Thermistor Digital Out connects to PCF8591 AIN0
* PCF8591 Connects to main SDA & SCL (by 3.3V)
* Leaves backups available for screen