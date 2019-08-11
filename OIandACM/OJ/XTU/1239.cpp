#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	int k;
	//string f;
	int map[9][9];
	char s[9];
	int top;
	//cin >> k;
	scanf("%d", &k);

	while(k--){
		memset(map, 0, sizeof(map));
		for(int i = 1; i <= 4; i++)
			for(int j = 1; j <= 4; j++)
				scanf("%d", &map[i][j]);
				//cin >> map[i][j];
		scanf("%s", s);
		// cin >> f;
		switch(s[0]){
			case 'L':
				// top = 0;
				for(int i = 1; i <= 4; i++){
					for(int j = 1; j <= 4; j++){// ->
						top = j + 1;
						while(map[i][top] == 0 && top <= 4)
							top++;
						if(map[i][j] == 0){
							if(top <= 4){
								map[i][j] = map[i][top];
								map[i][top] = 0;
								top++;
								while(map[i][top] == 0 && top <= 4)
									top++;
								if(top <= 4 && map[i][j] == map[i][top]){
									map[i][j] <<= 1;
									map[i][top] = 0;
								}
							}
						}else{
							if(top <= 4 && map[i][j] == map[i][top]){
								map[i][j] <<= 1;
								map[i][top] = 0;
							}
						}
					}
				}
				break;
			case 'R':
				for(int i = 1; i <= 4; i++){
					for(int j = 4; j >= 1; j--){// ->
						top = j - 1;
						while(map[i][top] == 0 && top >= 1)
							top--;
						if(map[i][j] == 0){
							if(top >= 1){
								map[i][j] = map[i][top];
								map[i][top] = 0;
								top--;
								while(map[i][top] == 0 && top >= 1)
									top--;
								if(top >= 1 && map[i][j] == map[i][top]){
									map[i][j] <<= 1;
									map[i][top] = 0;
								}
							}
						}else{
							if(top >= 1 && map[i][j] == map[i][top]){
								map[i][j] <<= 1;
								map[i][top] = 0;
							}
						}
					}
				}
				break;
			case 'U':
				for(int i = 1; i <= 4; i++){
					for(int j = 1; j <= 4; j++){// ->
						top = j + 1;
						while(map[top][i] == 0 && top <= 4)
							top++;
						if(map[j][i] == 0){
							if(top <= 4){
								map[j][i] = map[top][i];
								map[top][i] = 0;
								top++;
								while(map[top][i] == 0 && top <= 4)
									top++;
								if(top <= 4 && map[j][i] == map[top][i]){
									map[j][i] <<= 1;
									map[top][i] = 0;
								}
							}
						}else{
							if(top <= 4 && map[j][i] == map[top][i]){
								map[j][i] <<= 1;
								map[top][i] = 0;
							}
						}
					}
				}
				break;
			case 'D':
				for(int i = 1; i <= 4; i++){
					for(int j = 4; j >= 1; j--){// ->
						top = j - 1;
						while(map[top][i] == 0 && top >= 1)
							top--;
						if(map[j][i] == 0){
							if(top >= 1){
								map[j][i] = map[top][i];
								map[top][i] = 0;
								top--;
								while(map[top][i] == 0 && top >= 1)
									top--;
								if(top >= 1 && map[j][i] == map[top][i]){
									map[j][i] <<= 1;
									map[top][i] = 0;
								}
							}
						}else{
							if(top >= 1 && map[j][i] == map[top][i]){
								map[j][i] <<= 1;
								map[top][i] = 0;
							}
						}
					}
				}
				break;
		}
		for(int i = 1; i <= 4; i++){
			for(int j = 1; j < 4; j++)
				printf("%d ", map[i][j]);
				// cout << map[i][j] << " ";
			printf("%d\n", map[i][4]);
			// cout << endl;
		}
		putchar('\n');
	}
	return 0 ;
}