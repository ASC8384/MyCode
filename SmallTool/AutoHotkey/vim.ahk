!CapsLock::escp := !escp

;移动
$h::Send % escp ? "h" : "{Left}"
$j::Send % escp ? "j" : "{Down}"
$k::Send % escp ? "k" : "{Up}"
$l::Send % escp ? "l" : "{Right}"
$w::Send % escp ? "w" : "^{Left}"
$b::Send % escp ? "b" : "^{Right}"
$^d::Send % escp ? "^d" : "{PgDn}"
$^u::Send % escp ? "^u" : "{PgUp}"

;操作
$x::Send % escp ? "x" : "{Backspace}"	;退格
$u::Send % escp ? "u" : "^z"			;撤销
$f::Send % escp ? "f" : "^f"			;搜索
$p::Send % escp ? "p" : "^v"			;粘贴
$y::Send % escp ? "y" : "^c"			;复制
$d::Send % escp ? "d" : "^x"			;剪贴
$^r::Send % escp ? "^r" : "^y"			;撤销的撤销
$^v::Send % escp ? "^v" : ""			;正常粘贴
$^c::Send % escp ? "^c" : ""			;正常复制

;选取
$v::Send, v
$+v::Send, V
v & h::Send % escp ? "vh" : "+{Left}"		;向左选
v & j::Send % escp ? "vj" : "+{Down}"		;向下选
v & k::Send % escp ? "vk" : "+{Up}"			;向上选
v & l::Send % escp ? "vl" : "+{Right}"		;向右选
v & w::Send % escp ? "vw" : "^+{Left}"		;向左选一个单词
v & b::Send % escp ? "vb" : "^+{Right}"		;向右选一个单词

#NoTrayIcon
