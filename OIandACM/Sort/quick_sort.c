/**********************************************************************
*                                quick_sort.c                         *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		quick_sort.c
** Description	快速排序
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/
//int a[sizesize];
void quicksort(int left,int right)
{
    int tl = left;
    int tr = right;
    int mid = a[(left+right)/2];
    int t;
    do
    {
        while(a[tl] < mid) tl++;
        while(a[tr] > mid) tr--;
        if (tl <= tr)
        {
            t = a[tl];
            a[tl] = a[tr];
            a[tr] = t;
            tr--;
            tl++;
        }
    } while (tl < tr);
    if (tl < right) quicksort(tl,right);
    if (tr > left) quicksort(left,tr);
}
//quicksort(1,n);

//从1开始,到n结束
