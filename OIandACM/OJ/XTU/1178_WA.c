#include <stdio.h>

inline int minn(int x, int y){
	return (x < y) ? x : y;
}

inline int maxn(int x, int y){
	return (x < y) ? y : x;
}

int main()
{
	int k;
	//int a[1230][1009];
	int x1, x2, y1, y2;
	int a1, a2, b1, b2;
	scanf("%d", &k);

	while(k--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		if(minn(x2, a2) > maxn(x1, a1) && minn(y2, b2) > maxn(y1, b1))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}