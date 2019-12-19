    #include <bits/stdc++.h>
    using namespace std;
     
    int a[33];
     
    int main()
    {
    	cin.tie(0);
    	ios::sync_with_stdio(0);
    	
    	int t;
    	cin >> t;
    	while(t--){
    		cin >> a[1] >> a[2] >> a[3];
    		sort(a + 1, a + 4);
    		if(a[1] == a[2] && a[2] == a[3])
    			cout << "0" << endl;
    		// else if(a[2] ==)
    		else// if(a[2] == a[3])
    			cout << max(((a[3] - a[1] - 2) << 1), 0) << endl;
    		// else
    			// cout << (a[3] - a[1])
    	}
     
    	return 0;
    }