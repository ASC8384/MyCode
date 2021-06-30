#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int	   a[344];
bool   f[344];
string s;

int main() {
	cin.tie(0);
	cout.tie(0);
	//ios::sync_with_stdio(0);

	while(cin >> s) {
		int len = s.size();
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		//cout << len << '\n';
		for(int i = 0; i < len; i++) {
			if(isalpha(s[i]))
				a[s[i] - 'A' + 1]++;
		}
		int maxx = 0;
		int d	 = 0;
		for(int i = 'A'; i <= 'Z'; i++) {
			d = __gcd(d, a[i - 'A' + 1]);
			// maxx = max(maxx, a[i - 'A' + 1]);
		}
		for(int i = 'A'; i <= 'Z'; i++) {
			a[i - 'A' + 1] /= d;
			// maxx = max(maxx, a[i - 'A' + 1]);
		}
		// maxx = max_element(a + 1, a + 'Z' - 'A' + 2);
        for(int i = 'A'; i <= 'Z'; i++) {
			// a[i - 'A' + 1] /= d;
			maxx = max(maxx, a[i - 'A' + 1]);
		}
		//cout << maxx << '\n';
		for(int i = maxx; i > 0; i--) {
			string ss = "";
			for(int j = 'A'; j < 'Z'; j++) {
				if(a[j - 'A' + 1] >= i)
					ss += "*";
				else if(a[j - 'A' + 1])
					ss += " ";
			}
			if(a['Z' - 'A' + 1] >= i)
				ss += "*";
			else if(a['Z' - 'A' + 1])
				ss += " ";
			int len = ss.size();
			for(int j = len - 1; j >= 0; j--)
				if(ss[j] == ' ')
					len = j;
				else
					break;
			for(int j = 0; j < len; j++)
				cout << ss[j];
			cout << '\n';
		}
		for(char i = 'A'; i <= 'Z'; i++)
			if(a[i - 'A' + 1])
				cout << i;
		cout << "\n\n";
	}

	return 0;
}