#include <bits/stdc++.h>
using namespace std;

int suma, sumb;
long long a, b;

//cnt = now's count
void dfs(long long now, long long cnt, int *sum, long long *n){
	if(cnt > 1 || now > *n)
		return;
	if(cnt == 1){
		*sum += 1;
		//*sum++;
		dfs(now << 1|1, cnt, sum, n);
	}else{
		dfs(now << 1, cnt + 1, sum, n);
		dfs(now << 1|1, cnt, sum, n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int k;
	//long long a, b;
	cin >> k;

	while(k--){
		cin >> a >> b;
		suma = sumb = 0;
		a--;
		//int *pa = &a, *pb = &b;
		//int *sa = &suma, *sb = &sumb;
		dfs(1, 0, &suma, &a);
		dfs(1, 0, &sumb, &b);
		cout << sumb - suma << endl;
	}
	return 0;
}
//a[i+1] = a[i] << 1 | 1 (+1);