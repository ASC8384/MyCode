XButton1::
	if (Existclass("ahk_exe firefox.exe") = 1){
		Send, {PgDn}
		Return
	}
	if (Existclass("ahk_exe Q-Dir_x64.exe") = 1){
		Send, {Click 2}
		Return
	}
	
Existclass(class)  
{
	MouseGetPos, , , win  
	WinGet, winid, id, %class%  
	if win = %winid%
		Return, 1  
	Else  
		Return, 0  
}

#NoTrayIcon