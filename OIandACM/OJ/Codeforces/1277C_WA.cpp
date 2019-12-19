    #include <bits/stdc++.h>
    using namespace std;
     
    // int a[81] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111,22, 222, 2222, 22222, 222222, 2222222, 22222222, 222222222,33, 333, 3333, 33333, 333333, 3333333, 33333333, 333333333,44, 444, 4444, 44444, 444444, 4444444, 44444444, 444444444,55, 555, 5555, 55555, 555555, 5555555, 55555555, 555555555,66, 666, 6666, 66666, 666666, 6666666, 66666666, 666666666,77, 777, 7777, 77777, 777777, 7777777, 77777777, 777777777,88, 888, 8888, 88888, 888888, 8888888, 88888888, 888888888,99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999,};
    string s;
    int a[233333];
     
    int main()
    {
    	cin.tie(0);
    	ios::sync_with_stdio(0);
    	
    	int t;
    	cin >> t;
    	
    	while(t--){
    		cin >> s;
    //		s = s;
    		size_t pos = 0;
    		int ans = 0;
    		int ll = s.size();
    		for(pos = s.rfind("one"); pos != string::npos; pos = s.rfind("one", ll - pos + 1)){
    			//for(; s[pos] == 'o'; pos--){
    			if(pos >= 1 && s[pos-1] == 'o'){
    				s[pos+1] = ' ';
    				// s.erase(pos+1, pos+2);
    				a[++ans] = pos+1;
    			}else{
    				s[pos] = ' ';
    				// s.erase(pos, pos+1);
    				a[++ans] = pos;
    			}
    		}
    		ll = s.size();
    		// cout << s << endl;
    		for(pos = s.rfind("two"); pos != string::npos; pos = s.rfind("two", ll - pos + 1)){
    			//for(; s[pos] == 't'; pos--){
    			if(pos >= 1 && s[pos-1] == 't'){
    				s[pos+1] = ' ';
    				a[++ans] = pos+1;
    			}else{
    				s[pos] = ' ';
    				a[++ans] = pos;
    			}
    		}
    		cout << ans << endl;
    		for(int i = 1; i <= ans; i++)
    			cout << a[i]+1 << " ";
    		cout << endl;
    	}
     
    	return 0;
    }