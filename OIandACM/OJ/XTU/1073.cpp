#include <cstdio>
#include <algorithm>

int main()
{
	int a[3];
	for(int i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	std::sort(a, a + 3);
	printf("%d %d", a[2], a[0]);
	return 0;
}