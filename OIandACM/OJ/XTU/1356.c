#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int xx[5] = {0, -1, 0, 1, 0};
int yy[5] = {0, 0, 1, 0, -1};
char s[233];
int map[233][233];
int f[233][233][6];
 
int main()
{
    int t;
    int n, m, d;
    int x, y;
    int ex, ey;
    scanf("%d", &t);
     
    while(t--){
        memset(s, 0, sizeof(s));
        memset(map, 0, sizeof(map));
        memset(f, 0, sizeof(f));
        scanf("%d%d%d", &n, &m, &d);
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            for(int j = 1; j <= m; j++)
                if(s[j-1] == 'S'){
                    x = i;
                    y = j;
                    map[i][j] = 1;
                }else if (s[j-1] == 'E'){
                    ex = i;
                    ey = j;
                    map[i][j] = 0;
                }else if(s[j-1] == '.')
                    map[i][j] = 1;
                else if(s[j-1] == '*')
                    map[i][j] = 0;
        }
        int ans = 0;
        char flag = 1;
        f[x][y][d]++;
        while(flag){
            while(map[x+xx[d]][y+yy[d]] != 0){
                x += xx[d];
                y += yy[d];
                //map[x][y] = 2;
                if(f[x][y][d] != 0){
                    flag = 0;
                    break;
                }else
                    f[x][y][d]++;
                ans++;
            }
            if(flag == 0){
                ans = 0;
                break;
            }
            if(x+xx[d] == ex && y+yy[d] == ey){
                ans++;
                break;
            }else{
                d++;
                if(d == 5)
                    d = 1;
                if(f[x][y][d] != 0){
                    flag = 0;
                    ans = 0;
                    break;
                }else
                    f[x][y][d]++;
            }
        }
        if(ans)
            printf("%d\n", ans);
        else
            printf("Impossible\n");
    }
    return 0;
}
/**************************************************************
    Problem: 1066
    User: ASC_8384
    Language: C
    Result: 正确
    Time:45 ms
    Memory:2604 kb
****************************************************************/
