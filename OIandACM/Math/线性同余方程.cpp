/**********************************************************************
*                                线性同余方程.cpp                                *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		线性同余方程.cpp
** Description	线性同余方程
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/

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

char linear_equation(int a, int b, int c, int &x, int &y){
	int d = extended_euclid(a, b, x, y);
	if(c % d)
		return 0;
	int k = c / d;
	x *= k;//+ t * b;
	y *= k;//- t * a;
	return 1;
}//a * x + b * y == c
/*
if(linear_equation(a, b, c, x, y))
	printf("%d %d", x, y);*/
