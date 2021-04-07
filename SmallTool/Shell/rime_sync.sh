cd ~/.config/ibus/rime
echo `pwd`
killall ibus-daemon
rime_dict_manager -s
nohup ibus-daemon -drx &
