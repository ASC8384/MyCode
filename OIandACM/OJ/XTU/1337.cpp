#include <bits/stdc++.h>
using namespace std;

char a[233];
char b[233];

int main()
{
	// int t = init();
	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%s", a);
		scanf("%s", b);
		int la = strlen(a);
		int lb = strlen(b);
		register int i, j;
		bool f = true;
		for(i = 0; i < la && f; i++)
			if(b[0] == a[i]){
				int pos = i;
				for(j = 0; j < lb; j++){
					if(b[j] == a[pos]){
						pos = (pos + 1) % la;
					}else{
						break;
					}
				}
				if(j == lb){
					f = false;
					break;
				}
				pos = i;
				for(j = 0; j < lb; j++){
					if(b[j] == a[pos]){
						pos = (abs(pos - 1 + la)) % la;
					}else{
						break;
					}
				}
				if(j == lb){
					f = false;
					break;
				}
			}
		if(f)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}