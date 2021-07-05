#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[23][23], b[23][23], c[23][23];

ll calc(int x, int y){
    ll ret = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ret += a[x+i][y+j];
        }
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        ll ans = 0;
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 4; j++){
                b[j][4] = a[1][j];
                b[4][j] = a[5-j][4];
                b[j][1] = a[4][j];
                b[1][j] = a[5-j][1];
            }
            for(int x = 1; x <= 4; x++){
                for(int y = 1; y <= 4; y++){
                    a[x][y] = b[x][y];
                }
            }
            for(int x = 1; x <= 3; x++){
                for(int y = 1; y <= 3; y++){
                    ll tmp = calc(x, y);
                    ans = max(ans, tmp);
                }
            }
        }
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 4; j++){
                b[j][1] = a[1][5-j];
                b[1][j] = a[j][4];
                b[j][4] = a[4][5-j];
                b[4][j] = a[j][1];
            }
            for(int x = 1; x <= 4; x++){
                for(int y = 1; y <= 4; y++){
                    a[x][y] = b[x][y];
                }
            }
            for(int x = 1; x <= 3; x++){
                for(int y = 1; y <= 3; y++){
                    ll tmp = calc(x, y);
                    ans = max(ans, tmp);
                }
            }
        }
        cout << ans << '\n';
	}

	return 0;
}