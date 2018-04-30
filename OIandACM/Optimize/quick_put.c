void putit(int x){
	if(x / 10){
		putit(x / 10);
	}
	putchar(x % 10 + '0');
}
