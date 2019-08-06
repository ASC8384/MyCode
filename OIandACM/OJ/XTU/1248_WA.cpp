#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k;
	int a[4], b[4];
	cin >> k;

	while(k--){
		for(int i = 1; i <= 3; i++){
			cin >> a[i];
			if(a[i] == 1)
				a[i] = 7;
		}
		for(int i = 1; i <= 3; i++){
			cin >> b[i];
			if(b[i] == 1)
				b[i] = 7;
		}
		sort(a+1, a+3);
		sort(b+1, b+3);
		if(a[1] == a[2] && a[2] == a[3])
			if(b[1] == b[2] && b[2] == b[3])
				if(a[1] > b[1])
					cout << "Alice" << endl;
				else if(a[1] < b[1])
					cout << "Bob" << endl;
				else
					cout << "Draw" << endl;
			else 
				cout << "Bob" << endl;
		else
		if(b[1] == b[2] && b[2] == b[3])
			cout << "Bob" << endl;
		else
		if(a[1] == a[2] || a[2] == a[3])
			if(b[1] == b[2] || b[2] == b[3])
				if(a[2] > b[2])
					cout << "Alice" << endl;
				else if(a[2] < b[2])
					cout << "Bob" << endl;
				else
					cout << "Draw" << endl;
			else
				cout << "Alice" << endl;
		else{
			a[1] += a[2] + a[3];
			b[1] += b[2] + b[3];
			if(a[1] > b[1])
				cout << "Alice" << endl;
			else if(a[1] < b[1])
				cout << "Bob" << endl;
			else
				cout << "Draw" << endl;	
		}
	}
	return 0;
}