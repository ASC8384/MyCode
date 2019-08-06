#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	int x, y;
	int xx[4] = {0, -1, 0, 1};
	int yy[4] = {1, 0, -1, 0};
	//shang, zuo, xia, you
	int f, c;
	string s;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		x = y = f = 0;
		while(n--){
			cin >> s;
			switch(s[0]){
				case 'F':	cin >> c;
							x += xx[f]*c;
							y += yy[f]*c;
							break;
				case 'L':	f = (f+1) % 4;
							break;
				case 'R':	f = (f+3) % 4;
							break;
				case 'B':	f = (f+2) % 4;
							break;
			}
		}
		cout << x << " " << y << endl;
	}
	return 0;
}