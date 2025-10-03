#!/bin/bash
current_rate=$(cat /home/h1tae/.config/hypr/rate.txt)
echo "\$rate=$current_rate" > ~/.config/hypr/rate.conf
echo "<b>$current_rate</b>"