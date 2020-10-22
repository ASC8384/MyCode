#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int	   a[344];
string s;

int main() {
	cin.tie(0);
	cout.tie(0);
	//ios::sync_with_stdio(0);

	while(cin >> s) {
		int len = s.size();
		//cout << len << '\n';
		for(int i = 0; i < len; i++) {
			if(isalpha(s[i]))
				a[s[i] - 'A' + 1]++;
		}
	}

	int maxx = 0;
	for(int i = 'A'; i <= 'Z'; i++) {
		maxx = max(maxx, a[i - 'A' + 1]);
	}
	//cout << maxx << '\n';
	for(int i = maxx; i > 0; i--) {
		string ss = "";
		for(int j = 'A'; j < 'Z'; j++) {
			if(a[j - 'A' + 1] >= i)
				ss += "* ";
			else
				ss += "  ";
		}
		if(a['Z' - 'A' + 1] >= i)
			ss += "*";
		else
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
	for(char i = 'A'; i < 'Z'; i++)
		cout << i << ' ';
	cout << 'Z';
	return 0;
}