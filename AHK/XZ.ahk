#Persistent
#SingleInstance, Force

Menu, Tray, NoStandard
Menu, Tray, Add, 重启 &r, re
Menu, Tray, Add, 退出 &x, ex

;CapsLock & v::Run, D:\gVim.lnk
;CapsLock & t::Run, D:\sublime.lnk
CapsLock & t::Run, \sublime.lnk, %A_WorkingDir%
CapsLock & v::Run, \gVim, %A_WorkingDir%
CapsLock & Z::Run, D:\

re:
	Reload
return
ex:
	ExitApp
return
