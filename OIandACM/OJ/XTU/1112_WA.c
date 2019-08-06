#include <stdio.h>

int main()
{
	int n;
	int a[9], i;
	//int x1, y1, x2, y2, x3, y3;
	scanf("%d", &n);

	while(n--){
		for(i = 0; i < 6; i++)
			scanf("%d", &a[i]);
		if((double)(a[1]-a[3]) / (double)(a[0]-a[2]) - 
			(double)(a[1]-a[5]) / (double)(a[0]-a[4]))
			printf("Yes\n");
		else
			printf("No\n");
		//scanf("%d%d%d%d%d", &x1, )
	}
	return 0;
}