void putit(int x){
	if(x / 10){
		putit(x / 10);
	}
	putchar(x % 10 + '0');
}



//...(...){
//........
		if(x < 0){
				putchar('-');
				x = -x;
				putit(x);
		}else
  		  putit(x);
//.......
