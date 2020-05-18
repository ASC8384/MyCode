#!/bin/bash

ret=$(ps ax | grep -v grep | grep sh/sh/wp_autochange)
if [ "$ret" != "" ]; then
	exit
fi

/usr/libexec/gsd-xsettings &

/bin/bash ~/code/sh/sh/wp_autochange.sh &
/bin/bash ~/code/sh/sh/dwm_status.sh &
/bin/bash ~/code/sh/sh/two_finger_scroll.sh &
/bin/bash ~/code/sh/sh/mapping_esc_caps.sh

picom -b --config ~/.config/picom.conf

sleep 1s
PID=$(ps a | grep -v grep | grep -w dwm | grep -v /usr/ | awk '{printf $1}')
kill -HUP $PID
