#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k;
	string f;
	int map[9][9];
	int top;
	cin >> k;

	while(k--){
		memsest(map, 0, sizeof(map));
		for(int i = 1; i <= 4; i++)
			for(int j = 1; j <= 4; j++)
				cin >> map[i][j];
		cin >> f;
		switch(s[0]){
			case 'L':
				// top = 0;
				for(int i = 1; i <= 4; i++){
					top = 1;
					for(int j = 1; j <= 4; j++){
						if(map[i][j]){
							while(map[i][++top] == 0 && top <= 4);
							if(map[i][j] == map[i][top]){
								map[i][j] <<= 1;
								map[i][top] = 0;
							}
						}else{
							while(map[i][++top] == 0 && top <= 4);
							map[i][j] = map[i][top];
							map[i][top] = 0;
							while(map[i][++top] == 0 && top <= 4);
							if(map[i][j] == map[i][top]){
								map[i][j] <<= 1;
								map[i][top] = 0;
							}
						}
					}
				}
				break;
		}
		for(int i = 1; i <= 4; i++){
			for(int j = 1; j <= 4; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
	}
	return 0 ;
}