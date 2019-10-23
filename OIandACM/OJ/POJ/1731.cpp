#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	do{
		cout << s << endl;
	}while(next_permutation(s.begin(),s.end()));
	return 0;
}