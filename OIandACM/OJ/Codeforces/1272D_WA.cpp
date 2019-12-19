    #include <bits/stdc++.h>
    using namespace std;
     
    int a[233333];
    int ans[233333];
     
    int main()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int tmp = 1;
        // int ans = 1;
        int ll = 1;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i+1])
                tmp++;
            else{
                for(int j = ll; j <= i; j++)
                    ans[j] = tmp;
                tmp = 1;
                ll = i + 1;
            }
        }
        if(a[n-1] < a[n]){
            for(int j = ll; j <= n; j++)
                ans[j] = tmp;
        }else
            ans[n] = 1;
        // ans = max(ans, tmp);
        // for(int i = 1, putchar('\n'); i <= n; i++)   cout << ans[i] << " ";
        int aa = 1;
        tmp = 1;
        for(int i = 1; i <= n; i++){
            aa = max(aa, ans[i]);
        }
    //  aa = max(aa, tmp);
        for(int i = 1; i < n; i++){
            if(ans[i+1] != ans[i] || (a[i+1] < a[i] && ans[i+1] == ans[i]) || (a[i] < a[i-1] && ans[i+1] == ans[i])){
                // aa = max(aa, ans[i-1] + ans[i+1]);
                if(a[i-1] < a[i+1])
                    aa = max(aa, ans[i-1] + ans[i+1] - 1);
                //else if(a[i] < a[i+1])
                //  aa = max(aa, ans[i-1] + ans[i+1]);
            }
        }
        if(aa < n)
            cout << aa << endl;
        else
            cout << n << endl;
     
        return 0;
    }