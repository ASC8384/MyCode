#!/bin/bash

ret=$(ps ax | grep -v grep | grep wp-autochange)
if [ "$ret" != "" ]; then
	exit
fi

/bin/bash ~/code/sh/sh/wp_autochange.sh &
/bin/bash ~/code/sh/sh/dwm_status.sh &
/bin/bash ~/code/sh/sh/two_finger_scroll.sh &

picom -b --config ~/.config/picom.conf

