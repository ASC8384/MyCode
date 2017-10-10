inline int init(void){
	int x;
	char c;
	int flag = 1;
	for(c = getchar(); !isdigit(c); c = getchar())
		if(c == '-')
			flag = -1;
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
	return x * flag;
}
