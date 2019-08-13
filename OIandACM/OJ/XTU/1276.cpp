#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int t = init();

	while(t--){
		int a = init();
		int b = init();
		if(a == b)
			printf("None\n");
		else if(a > b)
			cout << "Bob " << (a+b) / 2.0 - b << endl;
			// printf("Bob %lf\n", (a+b) / 2.0 - b);
		else
			cout << "Alice " << (a+b) / 2.0 - a << endl;
			// printf("Alice %lf\n", (a+b) / 2.0 - a);
	}
	return 0;
}