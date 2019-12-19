    #include <bits/stdc++.h>
    using namespace std;
     
    int ji(int x){
    	int i;
    	for(i = 1; (x & 1) == 0; i++){
    		x >>= 1;
    	}
    	return i-1;
    }
     
    int a[200005];
    int b[200005];
     
    int is(int n){
    	for(int i = 0; i < n; i++)
    		if((a[i]&1) == 0)
    			return true;
    	return false;
    }
     
    bool cmp(int x, int y){
    	return x > y;
    }
     
    int main()
    {
    	cin.tie(0);
    	ios::sync_with_stdio(0);
    	
    	int t;
    	cin >> t;
    	while(t--){
    		int n;
    		// int top = 0;
    		cin >> n;
    		for(int i = 0; i < n; i++){
    			cin >> a[i];
    		}
    		sort(a, a + n, cmp);
    		/*for(int i = 0; i < n-1; i++)
    			if(a[i] != a[i+1] && (a[i] & 1) == 0)
    				b[++top] = a[i];
    		if((a[n-1] & 1) == 0)
    			b[++top] = a[n-1];
    		while()
    		for(int i = 1; (b[i]&1) == 0 && i <= top; ++i){
    			for(int j = 1; j <= top; ++j){
    				if(i == j)
    					continue;
    				if(b[i] == b[j]){
    					b[j] >>= 1;
    				}
    			}
    		}
    		cout << i << endl;*/
    		int ans = 0;
    		while(is(n)){
    			for(int i = 0; i < n; i++){
    				if(a[i] & 1)
    					continue;;
    				for(int j = 0; j < n; j++){
    					if(i == j)
    						continue;
    					if(a[i] == a[j])
    						a[j] >>= 1;
    				}
    				a[i] >>= 1;
    				ans++;
    			}
    		}
    		cout << ans << endl;
    	}
     
    	return 0;
    }