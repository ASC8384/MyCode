/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-18 12:13:51
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 6250009;
const ll  mod  = 1e9 + 7;

vector<ll> v;

ll p, a;

bool numlist[size];
int	 pri[size], top;

bool is_prime(ll x) {
	if(x == 1)
		return false;
	if(x == 2 || x == 3)
		return true;
	if(x % 6 != 1 && x % 6 != 5)
		return false;
	for(int i = 5; i * i <= x; i += 6)
		if(x % i == 0 || x % (i + 2) == 0)
			return false;
	return true;
}

void init() {
	top = 0;
	for(ll i = 2; i <= 6250001; i++) {
		if(numlist[i] == false)
			pri[++top] = i;
		for(ll j = 1; j <= top && i * pri[j] <= 6250001; j++) {
			numlist[i * pri[j]] = true;
			if(i % pri[j] == 0)
				break;
		}
	}
	return;
}

bool is(ll n) {
	v.clear();
	ll sum = 0;
	for(ll i = 2; i <= 2500; i++) {
		while(n % i == 0) {
			v.push_back(i);
			sum += i;
			n /= i;
		}
		if(sum > 2500)
			return false;
        if(is_prime(n))
			break;
	}
	if(n > 1) {
		v.push_back(n);
		sum += n;
	}
	if(sum <= 2500)
		return true;
	else
		return false;
}

void print(ll x) {
	if(!x)
		return;
	if(x < 0)
		putchar('-'), x = -x;
	print(x / 10);
	putchar(x % 10 + '0');
}

void read(ll &X) {
	X		= 0;
	int	 w	= 0;
	char ch = 0;
	while(!isdigit(ch)) {
		w |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	if(w)
		X = -X;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	// cin >> p;
	init();
	read(p);
	int t;
	// read(t);
	scanf("%d", &t);
	// cin >> t;
	while(t--) {
		// cin >> a;
		read(a);
		for(ll i = 0; true; i++) {
			if(is(a)) {
				int ss = v.size();
				// print(ss);
				printf("%d ", ss);
				for(int i = 0; i < ss; i++) {
					print(v[i]);
					putchar(' ');
				}
				break;
			} else {
				a += p;
			}
		}
		// cout << '\n';
		putchar('\n');
	}

	return 0;
}