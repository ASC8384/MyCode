    #include <bits/stdc++.h>
    using namespace std;
     
    int a[233333];
     
    int main()
    {
    	cin.tie(0);
    	ios::sync_with_stdio(0);
    	
    	int n;
    	cin >> n;
    	for(int i = 1; i <= n; i++)
    		cin >> a[i];
    	int tmp = 1;
    	int ans = 1;
    	for(int i = 1; i < n; i++){
    		if(a[i+1] > a[i])
    			tmp++;
    		else{
    			ans = max(ans, tmp);
    			tmp = 1;
    		}
    	}
    	ans = max(ans, tmp);
    	for(int i = 1; i <= n; i++){
    		tmp = 1;
    		// ans = 1;
    		for(int j = 1; j < n; j++){
    			if(i != j-1 && i != j){
    				if(a[j+1] > a[j])
    					tmp++;
    				else{
    					ans = max(ans, tmp);
    					tmp = 1;
    				}
    			// }else if(i == j){
    			// 	if(a[j+1] > a[j-1])
    			// 		tmp++;
    			// 	else{
    			// 		ans = max(ans, tmp);
    			// 		tmp = 1;
    			// 	}
    			// 	// j++;
    			}else if(i == j-1){
    				if(a[j+2] > a[j])
    					tmp++;
    				else{
    					ans = max(ans, tmp);
    					tmp = 1;
    				}
    				j++;
    			}
    		}
    		if(a[n] > a[n-1])
    			tmp++;
    		ans = max(ans, tmp);
    	}
    	if(ans < n)
    		cout << ans << endl;
    	else
    		cout << n << endl;
     
    	return 0;
    }