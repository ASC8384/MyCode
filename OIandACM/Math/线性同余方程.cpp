int extended_euclid(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int ret = extended_euclid(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ret;
}

char linearEquation(int a, int b, int c, int &x, int &y){
	int d = extended_euclid(a, b, x, y);
	if(c % d)
		return 0;
	int k = c / d;
	x *= k;//+ t * b;
	y *= k;//- t * a;
	return 1;
}//a * x + b * y == c
/*
if(linearEquation(a, b, c, x, y))
	printf("%d %d", x, y);*/
