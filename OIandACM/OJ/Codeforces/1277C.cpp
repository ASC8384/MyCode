#include <bits/stdc++.h>
using namespace std;
 
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
		// int ll = s.size();
		for(pos = s.rfind("one"); pos != string::npos; pos = s.rfind("one", pos + 1)){
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
		// ll = s.size();
		// cout << s << endl;
		for(pos = s.rfind("two"); pos != string::npos; pos = s.rfind("two", pos + 1)){
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
// netw netwoo eooo etwoooq