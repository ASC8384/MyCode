#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k, n;
	int a, b, c, x;
	cin >> k;

	while(k--){
		a = b = c = -1;
		cin >> n;
		if(n <= 3){
			cout << "Yes" << endl;
			break;
		}
		while(n--){
			cin >> x;
			if(x == a || x == b || x == c)
				if(a != -1 && b != -1 && c != -1)
					break;
			if(a == -1)
				a = x;
			else if(b == -1)
				b = x;
			else if(c == -1)
				c = x;
		}
		n++;
		while(n--){
			cin >> x;
			if(x != a && x != b && x != c)
				break;
		}
		n++;
		//cout << n << endl;
		if(n){
			cout << "Yes" << endl;
			//char s = getchar();
			//getchar();
			//putchar(s);
				//putchar(s);
		}else{
			cout << "No" << endl;
			while(k && getchar() != '\n');
		}
	}
	return 0;
}