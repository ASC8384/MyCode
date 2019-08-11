#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	int x1, x2, y1, y2;
	int a1, a2, b1, b2;
	scanf("%d", &k);

	while(k--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		if(min(max(x1, x2), max(a1, a2)) > max(min(x1, x2), min(a1, a2)) &&
			min(max(y1, y2), max(b1, b2)) > max(min(y1, y2), min(b1, b2)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}