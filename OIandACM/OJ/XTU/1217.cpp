#include <bits/stdc++.h>
using namespace std;

string s[] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int numb[] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};

string luoma(int n){
	string ret = "";
	for(int i = 0; i < 13 && n > 0; i++){
		if(n < numb[i])
			continue;
		while(n >= numb[i]){
			n -= numb[i];
			ret += s[i];
		}
	}
	return ret;
}

int main()
{
	int n;

	while(~scanf("%d", &n)){
		cout << luoma(n) << endl;
	}
	return 0;
}