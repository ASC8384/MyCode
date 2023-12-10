#l::
    DllCall("LockWorkStation")
    Sleep, 1000
    SendMessage 0x112, 0xF170, 2,,Program Manager
return

#o:: ; Win+O
    Sleep 1000 ; Give user a chance to release keys (in case their release would wake up the monitor again).
    ; Turn Monitor Off:
    SendMessage, 0x0112, 0xF170, 2,, Program Manager ; 0x0112 is WM_SYSCOMMAND, 0xF170 is SC_MONITORPOWER.
return

; https://www.autohotkey.com/docs/v1/lib/PostMessage.htm
