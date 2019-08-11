#include <stdio.h>

char is(unsigned int n){
	if(n % 6 != 1 && n % 6 != 5)
		return 0;
	int i;
	for(i = 5; i * i <= n; i++)
		if(n % i == 0 || n % (i + 2) == 0)
			return 0;
	return 1;
}

int main()
{
	unsigned int i, j, tmp, tmm = 1, tpp = 4, top = 4;
	unsigned int a[88] = {0, 2, 3, 5, 7};
	while(top < 83){//a.size()
		for(i = tmm; i <= tpp; i++){
			tmp = a[i] * 10;
			for(j = 0; j <= 9; j++){
				if(is(tmp + j))
					a[++top] = tmp + j;
			}
		}
		tmm = tpp + 1;
		tpp = top;
	}
	for(i = 1; i <= 83; i++){
		printf("%d %d\n", i, a[i]);
	}
	return 0;
}