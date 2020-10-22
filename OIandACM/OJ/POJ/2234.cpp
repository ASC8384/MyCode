#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n;
	while(cin >> n){
		int ans = 0;
		int a;
		for(int i = 1; i <= n; i++)
			cin >> a, ans ^= a;
		if(ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}
