/**********************************************************************
*                                quick_get.c                                *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		quick_get.c
** Description	快速输入
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}


inline int init_with(void){
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
