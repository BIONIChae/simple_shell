#!/bin/bash

max_pid=0
max_pid=$(cat /proc/sys/kernel/pid_max)
echo $max_pid
