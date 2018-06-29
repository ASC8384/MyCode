/**********************************************************************
*                          gcd_recursion.c                           *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		gcd_recursion.c
** Description	欧几里得算法
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
***********************************************************************/

int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
}
// recursion


int gcd(int x, int y){
	int tmp;
	while(y){
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}
// loop
