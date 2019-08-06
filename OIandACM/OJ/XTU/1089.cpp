#include <iostream>
using namespace std;

int main()
{
	int x;
	int i, ans;
	//scanf("%d", &n);

	while(cin >> x){
	//while(scanf("%d", &x) == 1){
		ans = 0;
		while(x % 2 == 0){
			++ans;
			x /= 2;
		}
		if(ans){
			//printf("%d", 2);
			cout << "2";
			if(ans != 1)
				//printf("^%d", ans);
				cout << '^' << ans;
			if(x != 1)
				//printf("*");
				cout << '*';
		}
		//scanf("%d", &x);
		for(i = 3; x != 1; i += 2){
			ans = 0;
			while(x % i == 0){
				++ans;
				x /= i;
			}
			if(ans){
				//printf("%d", i);
				cout << i;
				if(ans != 1)
					//printf("^%d", ans);
					cout << '^' << ans;
				if(x != 1)
					//printf("*");
					cout << '*';
			}
		}
		cout << endl;
		//putchar('\n');
	}
	return 0;
}