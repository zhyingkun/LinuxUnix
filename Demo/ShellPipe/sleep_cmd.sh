#! /bin/sh
sleep 1
echo "In sleep_cmd.sh" 1>&2
ps -ef | grep cmd | grep -v grep
