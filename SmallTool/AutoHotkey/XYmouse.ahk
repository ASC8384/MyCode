XButton1::
	MouseGetPos, xpos1, ypos1
	settimer, gtrack, 1
	Return

XButton1 up::
	settimer, gtrack, off
	if(gtrack = "l"){
		Send, ^#{left}
	}else if(gtrack = "r"){
		Send, ^#{right}
	}else if(gtrack = "u"){

	}else if(gtrack = "d"){

	}else{
		if (Existclass("ahk_exe firefox.exe") = 1){
			Send, {PgDn}
		}
		if (Existclass("ahk_exe Q-Dir_x64.exe") = 1){
			Send, {Click 2}
		}
	}
	gtrack =
return

XButton2::
	if (Existclass("ahk_exe firefox.exe") = 1){
		Send, {PgUp}
		Return
	}

Existclass(class){
	MouseGetPos, , , win
	WinGet, winid, id, %class%
	if win = %winid%
		Return, 1
	Else
		Return, 0
}

gtrack:
	mousegetpos xpos2,ypos2
	track := (abs(ypos1-ypos2) >= abs(xpos1-xpos2)) ? (ypos1>ypos2 ? "u" : "d") : (xpos1>xpos2 ? "l" : "r")
	if (track <> SubStr(gtrack, 0, 1)) and (abs(ypos1-ypos2) > 4 or abs(xpos1-xpos2) > 4)
		gtrack .= track
	xpos1 :=xpos2, ypos1 := ypos2
	return

#NoTrayIcon