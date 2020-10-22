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
	while(cin >> n && n){
		map<int,int> a;
		int ans = 0;
		int tmp;
		for(int i = 1; i <= n; i++)
			cin >> tmp, a[tmp]++;
		if(n & 1)
			ans = 1;
		else{
			// for(auto &i : a)
			map<int, int>::iterator i;
			for(i = a.begin(); i != a.end(); i++)
				if(i->second & 1){
					ans = 1;
					break;
				}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
