Loop
{
	Loop, 5
	{
		PixelSearch, px, py, 440,260,560,620, 0xFF3300, 4, Fast RGB
		if ErrorLevel = 0
		{
			;MsgBox, X%px% and Y%py%
			MouseMove, %px%, %py%, 0
			Sleep, 80
			Click
			MouseMove, 725, 987, 0
			Sleep, 80
			Click
			Sleep, 80
		}
	}
	MouseMove, 534, 935, 0
	Sleep, 80
	Click
}

F9::ExitApp
F11::Reload
