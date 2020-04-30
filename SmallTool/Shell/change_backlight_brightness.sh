#!/bin/bash

# remember to use root or sudo
echo $1 > /sys/class/backlight/intel_backlight/brightness
