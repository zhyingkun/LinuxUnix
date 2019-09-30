#! /usr/bin/env bash
ls -l /proc/`echo $$`/fd
ps -ef | grep `echo $$`
