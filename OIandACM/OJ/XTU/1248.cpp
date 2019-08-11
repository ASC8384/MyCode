#include <bits/stdc++.h>
using namespace std;

int a[5], b[5];

int main()
{
	ios::sync_with_stdio(false);
	int k;
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
		sort(a + 1, a + 4);
		sort(b + 1, b + 4);

		if(a[1] == a[2] && a[2] == a[3])
			a[0] = 3;
		else if(a[1] == a[2] || a[2] == a[3])
			a[0] = 2;
		else 
			a[0] = 1;
		if(b[1] == b[2] && b[2] == b[3])
			b[0] = 3;
		else if(b[1] == b[2] || b[2] == b[3])
			b[0] = 2;
		else 
			b[0] = 1;

		if(a[0] > b[0])
			cout << "Alice" << endl;
		else if(a[0] < b[0])
			cout << "Bob" << endl;
		else{
			if(a[0] == 3){
				if(a[1] > b[1])
					cout << "Alice" << endl;
				else if(a[1] < b[1])
					cout << "Bob" << endl;
				else
					cout << "Draw" << endl;
			}else if(a[0] == 1){
				if(a[3] == 7)
					a[3] = 1;
				if(b[3] == 7)
					b[3] = 1;
				a[1] = a[1] + a[2] + a[3];
				b[1] = b[1] + b[2] + b[3];
				if(a[1] > b[1])
					cout << "Alice" << endl;
				else if(a[1] < b[1])
					cout << "Bob" << endl;
				else
					cout << "Draw" << endl;
			}else{
				if(a[2] > b[2])
					cout << "Alice" << endl;
				else if(a[2] < b[2])
					cout << "Bob" << endl;
				else{
					if(a[1] == a[2])
						a[1] = a[3];
					if(b[1] == b[2])
						b[1] = b[3];
					if(a[1] > b[1])
						cout << "Alice" << endl;
					else if(a[1] < b[1])
						cout << "Bob" << endl;
					else
						cout << "Draw" << endl;
				}
			}
		}
	}
	return 0;
}