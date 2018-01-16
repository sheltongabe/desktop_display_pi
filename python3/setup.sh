#!/bin/bash

#must be run with admin permissions

#setup qt
apt install qt5-default

#setup speedtest for python
apt install pip3
pip3 install requests
pip3 install bs4

#remove screen timeout and poweroff timeout with /etc/kbd/config