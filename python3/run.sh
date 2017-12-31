#!/bin/bash

#setup traps so that if the script is killed by interupts or errors
#the background processes will be killed
trap "exit" SIGINT SIGTERM 
trap "kill 0" EXIT


#start python utility code for speedtesting
python3 tester.py &
TEST=$!
echo $TEST

#start the c++ gui
./application

wait

#kill the speedtester
#kill $TEST