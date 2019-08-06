#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n;
	long long a[2333];

	a[0] = 1;
	a[1] = 2;
	for(int i = 2; i <= 1333; i++)
		a[i] = a[i-1] + a[i-2];
	//for(int i = 1; i <= 86; i++)
	//	a[i] = (ans <<= 1);

	while(cin >> n){
		for(int i = 0; n > 0; i++){
			if(a[i] > n){
				cout << i - 1 << endl;
				break;
			}
		}
		/*for(int i = 0; i <= 86; i++){
			if(a[i] >= n){
				cout << i << endl;
				break;
			}
		}*/
	}
	return 0;
}