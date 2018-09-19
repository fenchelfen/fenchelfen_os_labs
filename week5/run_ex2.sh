#!/bin/bash

cat /dev/null > file

watch -n 0.4 cat file & 
while true; do ps -ef | grep ex2.sh | grep -v vim > file; done &

bash ex2.sh &
bash ex2.sh
