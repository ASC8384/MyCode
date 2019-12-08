#include <stdio.h>
#include <string.h>
#include <math.h>
 
const int mo = 1e9+7;
 
int map[144][144];
 
int main()
{
    int t;
    scanf("%d", &t);
    map[0][0] = 1;
    for(int i = 1; i < 123; i++)
        map[0][i] = map[i][0] = 1;
    for(int i = 1; i < 123; i++)
        for(int j = 1; j < 123; j++)
            map[i][j] = ((map[i][j-1] + map[i-1][j]) % mo + map[i-1][j-1]) % mo;
     
     
    int n, m;
    while(t--){
        scanf("%d%d", &n, &m);
        printf("%d\n", map[n][m]);
    }
    return 0;
}
/**************************************************************
    Problem: 1064
    User: ASC_8384
    Language: C
    Result: 正确
    Time:17 ms
    Memory:1200 kb
****************************************************************/
