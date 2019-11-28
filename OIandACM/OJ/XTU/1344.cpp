#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
	string a;
	while(cin >> a){
		int ans = 1;
		int tmp = 0;
		int ll = a.size();
		for(int i = 1; i < ll; i++){
			if(a[i] == a[i-1] + 1)
				ans++;
			else{
				tmp = max(ans, tmp);
				ans = 1;
			}
		}
		tmp = max(ans, tmp);
		cout << tmp << endl;
	}
	return 0;
}