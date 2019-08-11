#include<bits/stdc++.h>
using namespace std;
 
string no[] = {"13", "31",
				"17", "71",
				"19", "91",// 1
				"28", "82",// 2
				"37", "73",
				"39", "93",// 3
				"46", "64",// 4
				"79", "97"};// 7

int main()
{
	string s;
	int t, pos;
	char flag;
	scanf("%d", &t);

	while(t--)
	{
		cin >> s;
		flag = 1;
		for(int i = 0; i < 16; i++){
			pos = s.find(no[i]);
			if(pos != -1){
				if(pos < s.find((no[i][0] + no[i][1]) >> 1)){
					flag =false;
					break;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}