#!/bin/bash

/bin/bash ~/code/dwm/sh/wp-autochange.sh &
/bin/bash ~/code/dwm/sh/dwm-status.sh &
/bin/bash ~/code/dwm/sh/two-finger-scroll.sh &

picom -b
