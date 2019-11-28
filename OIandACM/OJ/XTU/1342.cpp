#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
	int a[5];
	int b[5];
	int t;
	cin >> t;

	while(t--){
		for(int i = 0; i < 3; i++)
			cin >> a[i];
		for(int i = 0; i < 3; i++)
			cin >> b[i];
		sort(a, a + 3);
		sort(b, b + 3);
		if(a[0]*b[1]==a[1]*b[0] && a[1]*b[2]==a[2]*b[1] && a[0]*b[2]==a[2]*b[0])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
} 