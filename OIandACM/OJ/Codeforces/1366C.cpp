#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 99;
inline void				   qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &... ls) {
	register T1	  __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar()))
		___ = (ch == '-') ? -___ : ___;
	do {
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	} while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return;
}

bool ma[size][size];
int	 a[size];
int	 b[size];

int main() {
	int t;
	qread(t);
	while(t--) {
		int n, m;
		qread(n, m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				qread(ma[i][j]);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int mid = n + m - 2;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				int tmp = i + j - 2;
				if(ma[i][j])
					a[tmp]++;
				b[tmp]++;
			}
		int ans = (ma[1][1] != ma[n][m]);
		if(mid & 1) {
			// mid >>= 1;
			for(int i = 1; i <= mid / 2; i++) {
				a[i] += a[mid - i];
				b[i] += b[mid - i];
				ans += min(b[i] - a[i], a[i]);
			}
		} else {
			for(int i = 1; i <= mid / 2; i++) {
				if(i == mid / 2)
					continue;
				a[i] += a[mid - i];
				b[i] += b[mid - i];
				ans += min(b[i] - a[i], a[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int A[510000],B[510000];
bool is_prime(int x){
    if(x==1)
        return false;
    if(x==2||x==3)
        return true;
    if(x%6!=1&&x%6!=5)
        return false;
    int s=sqrt(x);
    for(int i=5;i<=s;i+=6)
        if(x%i==0||x%(i+2)==0)
            return false;
    return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		int b=a;
		int k=0,ans=0,ans1;
		if(is_prime(a))
		{
			A[i]=-1;
			B[i]=-1;
			continue;
		}
		for(int j=2;j<=sqrt(b);j++)
			if(b%j==0)
			{
				k++;
				if(k==1&&j!=2)ans1=j;
				if(k==2&&j!=2)
				{
					ans=j;
					break;
				}
				while(b%j==0)b/=j;
			}
		if(k<2&&b!=1)
		{
			k++;
			if(k==1&&b!=2)ans1=b;
			if(k==2&&b!=2)
			{
				ans=b;
			}
		}
		if(k<2)
		{
			A[i]=-1;
			B[i]=-1;
			continue;
		}
		if(a%2==0)
		{
			A[i]=2;
			while(a%2==0)
				a/=2;
			B[i]=a;
		}
		else
		{
			A[i]=ans1;
			B[i]=ans;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",A[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",B[i]);
}
