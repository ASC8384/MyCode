/**********************************************************************
*                                insert_sort.c                         *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		insert_sort.c
** Description	插入排序
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/

void insertsort(int a[]){
	for(int i = 2; i <= n; i++){
		int t = a[i];
		int j = i - 1;
		while(t < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
