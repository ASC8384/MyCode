/**********************************************************************
*                                quick_put.c                          *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		quick_put.c
** Description	快速读取
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/

void putit(int x){
	if(x / 10){
		putit(x / 10);
	}
	putchar(x % 10 + '0');
}


//...(...){
//........
		if(x < 0){
				putchar('-');
				x = -x;
				putit(x);
		}else
  		  putit(x);
//.......
