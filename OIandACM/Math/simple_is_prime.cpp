/**********************************************************************
*                          simple_is_prime.cpp                           *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		simple_is_prime.c
** Description	判断质数
** HomepageURL	https://github.com/ASC8384
** License		CC0
**********************************************************************/

bool simple_is_prime(int n){
	if(n == 1)
		return false;
	if(n == 2 || n == 3)
		return true;
	if(n % 6 != 1 && n % 6 != 5)
		return false;
	int t = sqrt(n);
	for(register int i = 5; i <= t; i += 6)
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}