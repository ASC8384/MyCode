/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-11-09 23:02:36
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

bool find_ch(string s, string ops) {
	return s.find(ops) != string::npos;
}

bool find_ch(string s, char ops) {
	return s.find(ops) != string::npos;
}

class DFA {
public:
	string letter; // 字符集
	string state;  // 状态集
	string begin;  // 开始状态
	string end;	   // 终结符
	bool   isDFA;
	DFA() {
		isDFA = true;
	}
	bool is(string s) {
		// string cur = begin[0];
		string cur;
		cur += begin[0];
		for(int len = 0; len < s.size(); ++len) {
			// cout << len << " " << cur << endl;;
			string tmp = "";
			for(auto j : rules) {
				// cout << 333 << ' ' << j.cur << endl;
				if(cur == j.xxx && j.yyy != "#")
					tmp += j.yyy;
			}
			// cout << 444 << ' ' << tmp << endl;
			if(!find_ch(tmp, s[len]))
				s[len] = '#';
			cur = move_nxt(cur, s[len]);
		}
		return find_ch(end, cur);
	}
	void get(string s) {
		// cout << "get " << s << endl;
		rules.push_back(rule(s));
		if(++numx[s.substr(0, 2)] > 1)
			isDFA = false;
	}

private:
	unordered_map<string, int> numx;
	struct rule {
		string xxx, nxt, yyy;
		rule(string s) {
			xxx = s[0];
			yyy = s[1];
			nxt = s[2];
		}
		rule(string _xxx, string _yyy, string _nxt) {
			xxx = _xxx;
			yyy = _yyy;
			nxt = _nxt;
		}
	};
	vector<rule> rules;
	string move_nxt(string c, char x) {
		string ss;
		ss += x;
		// cout << 111 << ' ' << c << ' ' << x << endl;
		for(auto i : rules) {
			// cout << 222 << ' ' << i.cur << ' ' << i.ini << endl;
			if(i.xxx == c && i.yyy == ss)
				return i.nxt;
		}
		return "?";
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	DFA dfa;

	string s;
	bool   is  = false;
	int	   cnt = 0;
	while(getline(cin, s)) {
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		// 只考虑单个字符
		if(s == "Q") {
			is = true;
			if(dfa.isDFA) {
				cout << "DFA\n";
				continue;
			} else {
				cout << "Not DFA\n";
				break;
			}
		}
		if(is) {
			if(dfa.is(s)) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			if(++cnt < 5) {
				if(cnt == 1) {
					dfa.letter = s + "#";
				} else if(cnt == 2) {
					dfa.state = s;
				} else if(cnt == 3) {
					dfa.begin = s;
				} else if(cnt == 4) {
					dfa.end = s;
				}
			} else { // 规则
				dfa.get(s);
			}
		}
	}

	return 0;
}
/*
0 1
X A Y
X
Y
X 0 Y
X 1 X
Y 0 X
Y 1 Y
Q
1010
10010
*/