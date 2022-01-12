/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-12-11 15:10:34
*/
/*计算FIRST和FOLLOW集合*/
#include <bits/stdc++.h>
using namespace std;

class Production {
public:
	string lhs;
	string rhs;
	Production(string _lhs, string _rhs) {
		lhs = _lhs;
		rhs = _rhs;
	}
};

class Grammar {
public:
	vector<Production>		 rules;
	map<string, set<string>> first_set;
	map<string, set<string>> follow_set;

	static const string DED;
	static const string DIV;
	static const string Epsilon;
	static const string Over;
	static const string Start;

	void getinProduction(string s);
	int	 isTerminal(string token);
	void make_first();
	void make_follow();

private:
	set<string> find_first(string rhs);
	set<string> find_follow(string rhs);
};
const string Grammar::DED(":="); // Deduce
const string Grammar::DIV("|");
const string Grammar::Epsilon("@");
const string Grammar::Over("#");
const string Grammar::Start("S");

void Grammar::getinProduction(string s) {
	size_t pos = s.find(Grammar::DED);
	if(pos != string::npos) {
		vector<string> rhss;
		string		   RHS = s.substr(pos + Grammar::DED.size());
		size_t		   now = 0; // 当前分割
		for(now = RHS.find(Grammar::DIV); now != string::npos; now = RHS.find(Grammar::DIV)) {
			rhss.push_back(RHS.substr(0, now));
			RHS = RHS.substr(now + 1);
		}
		rhss.push_back(RHS.substr(0, now));
		for(auto rhs : rhss) {
			Production tmp(s.substr(0, pos), rhs);
			rules.push_back(tmp);
		}
	}
}

void Grammar::make_first() {
	for(auto rule : rules) {
		set<string> tmp = find_first(rule.rhs);
		first_set[rule.lhs].insert(tmp.begin(), tmp.end());
	}
}

set<string> Grammar::find_first(string s) {
	set<string> ret, tmp;
	if(isTerminal(s) == 0) { // non terminal
		for(auto rule : rules) {
			if(rule.lhs != s)
				continue;
			tmp = find_first(rule.rhs); // recursion
			ret.insert(tmp.begin(), tmp.end());
		}
	} else if(isTerminal(s) == 1) { // terminal
		ret.insert(s.substr(0, 1));
	} else {
		set<string> _first = find_first(s.substr(0, 1));
		if(_first.find(Grammar::Epsilon) != _first.end()) { // exist epsilon
			int i = 1;
			while(_first.find(Grammar::Epsilon) != _first.end()) {
				tmp = _first;
				tmp.erase(Grammar::Epsilon); // remove epsilon
				ret.insert(tmp.begin(), tmp.end());
				if(isTerminal(s.substr(i)) == 1) { // terminal
					ret.insert(s.substr(i));
					break;
				}
				// recursion
				set<string> _first2 = find_first(s.substr(i++));
				tmp					= _first2;
				tmp.erase(Grammar::Epsilon); // remove epsilon
				ret.insert(tmp.begin(), tmp.end());
			}
		} else {
			tmp = _first;
			ret.insert(tmp.begin(), tmp.end());
		}
	}
	return ret;
}

void Grammar::make_follow() {
	follow_set[Grammar::Start].insert(Grammar::Over);
	for(auto rule : rules) {
		set<string> tmp = find_follow(rule.lhs);
		follow_set[rule.lhs].insert(tmp.begin(), tmp.end());
	}
}
map<string, int> vis;

set<string> Grammar::find_follow(string s) { // dfs
	set<string> ret, tmp;
	if(s == Grammar::Start)
		ret.insert(Grammar::Over);
	for(auto rule : rules) {
		string now = rule.lhs + rule.rhs; // hash
		for(auto ch : rule.rhs) {
			if(ch != s[0] || vis[now])
				continue;
			vis[now]   = 1;
			string tmd = rule.rhs.substr(rule.rhs.find(s) + 1);
			if(tmd != "") {									  // aBb
				tmp = find_first(tmd);						  // first(b)
				if(tmp.find(Grammar::Epsilon) != tmp.end()) { // exist epsilon
					tmp.erase(Grammar::Epsilon);			  // minus epsilon
					ret.insert(tmp.begin(), tmp.end());
					tmp = find_follow(rule.lhs); // follow(A)
					ret.insert(tmp.begin(), tmp.end());
				} else {
					ret.insert(tmp.begin(), tmp.end());
				}
			} else {			  // aB
				if(rule.lhs == s) // infinite loop
					continue;
				tmp = find_follow(rule.lhs); // follow(A)
				ret.insert(tmp.begin(), tmp.end());
			}
		}
		vis[now] = 0; //
	}
	return ret;
}

/*
** Return 1: a/aA
** Return 0: A
** Return 3: Aa
*/
int Grammar::isTerminal(string token) {
	if(token == Grammar::Epsilon)
		return 1;
	if(token.size() == 1) {
		return islower(token[0]) > 0;
	} else {
		if(islower(token[0]))
			return 1;
		else
			return 3;
	}
}

bool cmp(string a, string b) {
	if(a == Grammar::Epsilon || a == Grammar::Over)
		return false;
	if(b == Grammar::Epsilon || b == Grammar::Over)
		return true;
	return a < b;
}

int main() {
	string	s;
	Grammar g;
	while(cin >> s) {
		if(s == "Q")
			break;
		else
			g.getinProduction(s);
	}
	g.make_first();
	g.make_follow();
	vector<string> ou;
	ou.resize(g.first_set.size());
	int pos = 0;
	for(auto i = g.first_set.begin(); i != g.first_set.end(); i++) {
		string s;
		s += i->first + " {";
		vector<string> tmd(i->second.begin(), i->second.end());
		sort(tmd.begin(), tmd.end(), cmp);
		s += tmd[0];
		for(int j = 1; j < tmd.size(); j++)
			s += "," + tmd[j];
		s += "} {";
		ou[pos++] = s;
	}
	pos = 0;
	for(auto i = g.follow_set.begin(); i != g.follow_set.end(); i++) {
		string		   s;
		vector<string> tmd(i->second.begin(), i->second.end());
		sort(tmd.begin(), tmd.end(), cmp);
		s += tmd[0];
		for(int j = 1; j < tmd.size(); j++)
			s += "," + tmd[j];
		s += "}\n";
		ou[pos++] += s;
	}
	for(auto i : ou)
		cout << i;
	return 0;
}

/*
S:=aeT|Mb
M:=ceTM|@
T:=deT|eS|@
Q
M {c,@} {b}
S {a,b,c} {b,c,#}
T {d,e,@} {b,c,#}

S:=aA|bS
A:=bA|@
Q
A {b,@} {#}
S {a,b} {#}

M:=TB
T:=Ba|@
B:=Db|eT|@
D:=d|@
Q
B {b,d,e,@} {a,#}
D {d,@} {b}
M {a,b,d,e,@} {#}
T {a,b,d,e,@} {a,b,d,e,#}

*/