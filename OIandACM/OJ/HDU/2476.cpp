#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char a[233], b[233];
	while(~scanf("%s%s", a, b)) {
		int len = strlen(a);
		int f[233][233];
		int ans[233];

		for(int i = 0; i < len; i++)
			f[i][i] = 1;
		for(int i = len - 2; i >= 0; i--) {
			for(int j = i + 1; j < len; j++) {
				f[i][j] = f[i + 1][j] + 1;
				for(int k = i + 1; k <= j; k++)
					if(b[k] == b[i])
						f[i][j] = min(f[i][j], f[i + 1][k - 1] + f[k][j]);
			}
		}

		for(int i = 0; i < len; i++) {
			ans[i] = f[0][i];
			if(a[i] == b[i]) {
				if(i == 0)
					ans[i] = 0;
				else
					ans[i] = ans[i - 1];
			} else {
				for(int j = 0; j < i; j++)
					ans[i] = min(ans[i], ans[j] + f[j + 1][i]);
			}
		}

		printf("%d\n", ans[len - 1]);
	}
	return 0;
}