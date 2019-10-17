#include <bits/stdc++.h>
using namespace std;

int n, len;
int a[99];
bool f[99];
int sum;
int last;

bool cmp(int x, int y){
	return x > y;
}

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

bool dfs(int resum, int relen){
	if(resum == 0 && relen == 0){
		return true;
	}else{
		if(relen == 0)
			relen = len;
		for(int i = (relen != len ? last + 1 : 1); i <= n; i++){
			if(!f[i] && a[i] <= relen){
				if(a[i] == a[i - 1] && !f[i - 1])
					continue;
				last = i;
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
	
	// n = init();
	// while(n){
	while(cin >> n && n){
	//n = init();{
		bool over = true;
		sum = 0;
		for(int i = 1; i <= n; i++){
			//a[i] = init();
			cin >> a[i];
			sum += a[i];
		}
		sort(a + 1, a + n + 1, cmp);
		int tmp = sum >> 1;
		for(len = a[1]; len <= tmp; len++){//
			if(sum % len)//
				continue;
			memset(f, false, sizeof(f));
			last = 1;
			if(dfs(n, len)){
				cout << len << endl;
				over = false;
				//printf("%d\n", len);
				break;
			}
		}
		if(over)
			cout << sum << endl;
	}
	return 0;
}