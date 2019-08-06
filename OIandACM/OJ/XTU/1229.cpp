#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int flag, ans, tmp;

	while(cin >> s){
		flag = -1;
		ans = tmp = 0;
		for(int i = 0; i < 9; i++){
			if(s[i] == '?')
				flag = i;
			else
				ans += (s[i]-'0') * (10 - i);
		}
		if(flag == -1){
			ans = 11 - ans % 11;
			if(ans == 10)
				s[9] = 'X';
			else if(ans == 11)
				s[9] = '0';
			else
				s[9] = ans + '0';
		}else{
			int i;
			for(i = 0; i < 9; i++){
				tmp = ans + i * (10-flag);
				tmp = 11 - tmp % 11;
				if(tmp == 10 && s[9] == 'X')
					break;
				if(tmp == 11 && s[9] == '0')
					break;
				if(tmp == s[9] - '0')
					break;
			}
			s[flag] = i + '0';
		}
		cout << s << endl;
	}
	return 0;
}