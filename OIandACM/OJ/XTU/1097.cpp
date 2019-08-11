#include <bits/stdc++.h>
using namespace std;

bool cmpA(int x, int y){
	return x < y;
}

bool cmpB(int x, int y){
	return x > y;
}

int main()
{
	ios::sync_with_stdio(false);
	int k, n;
	int a[2333];
	char c;
	cin >> k;

	while(k--){
		cin >> n >> c;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		if(c == 'A')
			sort(a, a + n, cmpA);
		else
			sort(a, a + n, cmpB);
		for(int i = 0; i < n - 1; i++)
			cout << a[i] << " ";
		cout << a[n - 1] << endl;
	}
	return 0;
}