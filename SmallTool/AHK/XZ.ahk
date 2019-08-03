#Persistent
#SingleInstance, Force

Menu, Tray, NoStandard
Menu, Tray, Add, 重启 &r, re
Menu, Tray, Add, 退出 &x, ex

;CapsLock & v::Run, D:\gVim.lnk
;CapsLock & t::Run, D:\sublime.lnk
CapsLock & t::Run, \sublime, %A_WorkingDir%
CapsLock & v::Run, \gVim, %A_WorkingDir%
CapsLock & z::Run, D:\
Capslock & c::Run, C:\Users\xszxnoi27\Desktop\Dev-C++.lnk

re:
	Reload
return
ex:
	ExitApp
return
