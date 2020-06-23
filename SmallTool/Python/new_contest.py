import os
import sys

src = '''#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int size = 2e5+9;
const ll mod = 19260817;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		;
	}
    return 0;
}
'''


def create_file(src, name, num=6):
    for i in range(num):
        now = name + chr(i + ord('A')) + '.cpp'
        try:
            with open(now, 'x') as f:
                print('now create:' + now)
                f.write(src)
        except FileExistsError:
            print('error: ' + now + ' Exists')


if __name__ == "__main__":
    if (len(sys.argv) == 3):
        create_file(src, sys.argv[1], int(sys.argv[2]))
    elif (len(sys.argv) == 2):
        create_file(src, sys.argv[1])
    else:
        s = input().split()
        if (len(s) == 1):
            create_file(src, s[0])
        else:
            create_file(src, s[0], int(s[1]))