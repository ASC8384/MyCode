/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-25 12:08:43
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];
int maxx = 0;

void prt1(int x) {
	cout << '+';
	// string s(x, '-');
	// string s = "";
	for(int i = 1; i <= x; i++)
		cout << "-";
	// cout << s;
	cout << '+' << '\n';
}

void prt2(int x) {
	cout << '|';
	// string s(x, ' ');
	// string s = "";
	for(int i = 1; i <= x; i++)
		cout << " ";
	// cout << s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}

	if(maxx % 50 == 0)
		for(int i = 1; i <= n; i++) {
			prt1(a[i] * 50 / maxx);
			if(maxx == a[i]) {
				prt2(49);
				cout << '*' << '|' << a[i] << '\n';
			} else {
				prt2(a[i] * 50 / maxx);
				cout << '|' << a[i] << '\n';
			}
			prt1(a[i] * 50 / maxx);
		}
	else {
		for(int i = 1; i <= n; i++) {
			if(maxx % a[i] == 0) {
				prt1(a[i] * 50 / maxx);
				if(a[i] == maxx) {
					prt2(49);
					cout << '*' << '|' << a[i] << '\n';
				} else {
					prt2(a[i] * 50 / maxx);
					cout << '|' << a[i] << '\n';
				}
				prt1(a[i] * 50 / maxx);
			} else {
				prt1(a[i] * 50 / maxx + 1);
				prt2(a[i] * 50 / maxx + 1);
				cout << '|' << a[i] << '\n';
				prt1(a[i] * 50 / maxx + 1);
			}
		}
	}
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
long long P[110000],B[110000];
int C[110000];
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&P[i]);
	for(int i=1;i<=n;i++)
		if(!B[i])
		{
			C[0]=1;
			C[1]=i;
			while(P[C[C[0]]]!=C[1])
				C[++C[0]]=P[C[C[0]-1]];
			int k=C[0];
			while(C[0])
				B[C[C[0]--]]=k;
		}
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(B[i]!=1)
		{
			if(!ans)ans=B[i];
			else ans=gcd(B[i],ans);
		}
	long long ans1=ans;
	if(ans==0)
	{
		ans=1;
		ans1=1;
	}
	for(int i=1;i<=n;i++)
		if(B[i]!=1)
			ans1=(ans1*(B[i]/ans));
	cout<<ans1<<endl;
}