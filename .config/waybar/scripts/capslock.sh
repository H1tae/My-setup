#!/bin/bash
capslock=$(cat /sys/class/leds/input2::capslock/brightness)
caps_icon="<b><span color='#fa6b7e'></span></b>"
if [ "$capslock" = "0" ]; then
	caps_icon="<b><span color='#99e9c1'></span></b>"
fi
echo "$caps_icon"
