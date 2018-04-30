int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
}
