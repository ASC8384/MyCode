#!/bin/bash

ret=$(ps ax | grep -v grep | grep wp-autochange)
if [ "$ret" != "" ]; then
	exit
fi

/bin/bash ~/code/dwm/sh/wp-autochange.sh &
/bin/bash ~/code/dwm/sh/dwm-status.sh &
/bin/bash ~/code/dwm/sh/two-finger-scroll.sh &

picom -b --config ~/.config/picom.conf

