int gcd(int x, int y){
	int tmp;
	while(y){
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}
