/**********************************************************************
*                          quick_pow_mod.c                           *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		quick_pow_mod.c
** Description	快速幂
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
** Time			date
***********************************************************************/

int quick_pow_mod(int x, int n, int mod){
	int ret = 1;
	while (n > 0){
		if (n & 1)
			ret = ret * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ret;
}
