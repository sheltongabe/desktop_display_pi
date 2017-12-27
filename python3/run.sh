#!/bin/bash

#start python utility code for speedtesting
python3 tester.py &
tester_pid = $!

#start the c++ gui
./application

#kill the speedtester
kill $tester_pid