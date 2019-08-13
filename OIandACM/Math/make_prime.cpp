/**********************************************************************
*                       	   make_prime.cpp                         *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		make_prime.c
** Description	判断质数
** HomepageURL	https://github.com/ASC8384
** License		CC0
**********************************************************************/

const int size;
bool isp[size];
int pri[size];
int pri_top;

void make_prime(int maxn){
	memset(isp, true, sizeof(isp));
	isp[0] = isp[1] = false;
	for(int i = 2; i <= maxn; i++){
		if(isp[i])
			pri[++pri_top] = i;
		for(int j = 1; j <= pri_top && i * pri[j] <= maxn; j++){
			isp[i * pri[j]] = false;
			if(!(i % pri[j]))
				break;
		}
	}
}
// make_prime(size);