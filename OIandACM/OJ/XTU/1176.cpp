#include<bits/stdc++.h>
using namespace std;

char flag[233];

int main()
{
	int n;
	char c;
	char time[23][23], name[23][23];
	char tt[23], nn[23], su[23];
	int id;
	//memset(flag, 0, sizeof(char)*233);
	ios::sync_with_stdio(false);
	scanf("%d\n", &n);

	while(scanf("%s %s %d %s", tt, nn, &id, su) != EOF){
            //cout << su << endl;
			id -= 1000;
			if(su[0] == 'A')
			//if(strcmp(su,"Accepted") == 0)
				//tt = 3600*(10*time[0]+time[1]) + 60*(10*time[3]+time[4]) + (10*time[6]+time[7]);
				if(flag[id] == 0 || strcmp(tt, time[id]) < 0){
					flag[id] = 1;
					strcpy(name[id], nn);
					strcpy(time[id], tt);
				}
            while((c = getchar()) != '\n');
	}
	for(int i = 1; i <= n; i++){
		if(flag[i])
			printf("%d %s %s\n", i+1000, time[i], name[i]);
		else
        	printf("%d\n", i+1000);

	}
	return 0;
}