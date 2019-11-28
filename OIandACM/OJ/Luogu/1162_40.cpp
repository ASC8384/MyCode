#include <bits/stdc++.h>
using namespace std;

int n;
int mapp[33][33];
int a[33][33];
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};

void dfs(int r, int c){
    if(r < 0 || c >= n || c < 0 || r >= n || a[r][c] == 0)
        return;
    a[r][c] = 0;
    for(int i = 0; i < 4; i++)
        dfs(r + xx[i], c + yy[i]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> mapp[i][j];
            if(mapp[i][j] != 1)
                a[i][j] = 1;
        }
    dfs(0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j])
                cout << 2 << ' ';
            else
                cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}