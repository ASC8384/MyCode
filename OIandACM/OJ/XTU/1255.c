#include <stdio.h>
#include <math.h>

int main()
{
	int n, x, y, t;
	scanf("%d", &n);

	while(n--){
		scanf("%d%d", &x, &y);
		t = x*x + y*y;
		//printf("%d\n", (int)(sqrt(t) * (int)(sqrt(t))));
		if((int)(sqrt(t)) * (int)(sqrt(t)) == t){
			printf("%d\n", (int)sqrt(t));
			continue;
		}
		t = x*x - y*y;
		if(t > 0 && (int)(sqrt(t)) * (int)(sqrt(t)) == t){
			printf("%d\n", (int)sqrt(t));
			continue;
		}
		t = y*y - x*x;
		if(t > 0 && (int)(sqrt(t)) * (int)(sqrt(t)) == t){
			printf("%d\n", (int)sqrt(t));
			continue;
		}
		printf("None\n");
	}
	return 0;
}