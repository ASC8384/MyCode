#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	int a[3];

	cin >> n;
	while(n--){
		memset(a, 0, sizeof(a));
		cin >> s;
		for(int i = 0; i < s.size(); i++)
			if(s[i] == 'X')
				a[0]++;
			else if(s[i] == 'T')
				a[1]++;
			else if(s[i] == 'U')
				a[2]++;
		sort(a, a + 3);
		cout << a[0] << endl;
	}
}