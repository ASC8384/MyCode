#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

string s;
bool f[99];

int main()
{
	// while(~scanf("%s", s)){
	// while(cin >> s){
	while(getline(cin, s)){
		transform(s.begin(), s.end(), s.begin(), ::toupper);// algorithm
		int ll = s.size();
		int sum_ = 0;
		int suma = 0;
		memset(f, false, sizeof(f));
		int i;
		for(i = 0; i < ll; i++){
			if(s[i] == ' ')	
				sum_++;
			else{
				if(!f[s[i]]){
					f[s[i]] = true;
					suma++;
				}
			}
			if(suma > 10 || sum_ > 9){
				printf("No\n");
				break;
			}
		}
		if(i == ll)
			printf("Yes\n");
	}
	return 0;
}