#include <bits/stdc++.h>
using namespace std;

int n, len;
int a[99];
bool f[99];
int sum;

bool cmp(int x, int y){
	return x > y;
}

bool dfs(int resum, int relen){
	if(resum == 0 && relen == 0){
		return true;
	}else{
		if(relen == 0)
			relen = len;
		for(int i = 1; i <= n; i++){
			if(!f[i] && a[i] <= relen){
				if(a[i] == a[i - 1] && !f[i - 1])
					continue;
				f[i] = true;
				if(dfs(resum - 1, relen - a[i]))
					return true;
				f[i] = false;
				if(relen == a[i] || relen == len)
					return false;//
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(cin >> n && n){
		sum = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		sort(a + 1, a + n + 1, cmp);
		for(len = a[1]; len <= sum; len++){//
			if(sum % len)//
				continue;
			memset(f, false, sizeof(f));
			if(dfs(n, len)){
				cout << len << endl;
				//printf("%d\n", len);
				break;
			}
		}
	}
	return 0;
}