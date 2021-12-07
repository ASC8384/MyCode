// C语言词法分析器
#include <bits/stdc++.h>
using namespace std;
/* 不要修改这个标准输入函数 */
void read_prog(string& prog)
{
	char c;
	while(scanf("%c",&c)!=EOF){
		prog += c;
	}
}
/* 你可以添加其他函数 */

unordered_map<string, int> m;
vector<pair<int, int>>	   now;

void init() {
	m["auto"]	  = 1;
	m["break"]	  = 2;
	m["case"]	  = 3;
	m["char"]	  = 4;
	m["const"]	  = 5;
	m["continue"] = 6;
	m["default"]  = 7;
	m["do"]		  = 8;
	m["double"]	  = 9;
	m["else"]	  = 10;
	m["enum"]	  = 11;
	m["extern"]	  = 12;
	m["float"]	  = 13;
	m["for"]	  = 14;
	m["goto"]	  = 15;
	m["if"]		  = 16;
	m["int"]	  = 17;
	m["long"]	  = 18;
	m["register"] = 19;
	m["return"]	  = 20;
	m["short"]	  = 21;
	m["signed"]	  = 22;
	m["sizeof"]	  = 23;
	m["static"]	  = 24;
	m["struct"]	  = 25;
	m["switch"]	  = 26;
	m["typedef"]  = 27;
	m["union"]	  = 28;
	m["unsigned"] = 29;
	m["void"]	  = 30;
	m["volatile"] = 31;
	m["while"]	  = 32;
	m["-"]		  = 33;
	m["--"]		  = 34;
	m["-="]		  = 35;
	m["->"]		  = 36;
	m["!"]		  = 37;
	m["!="]		  = 38;
	m["%"]		  = 39;
	m["%="]		  = 40;
	m["&"]		  = 41;
	m["&&"]		  = 42;
	m["&="]		  = 43;
	m["("]		  = 44;
	m[")"]		  = 45;
	m["*"]		  = 46;
	m["*="]		  = 47;
	m[","]		  = 48;
	m["."]		  = 49;
	m["/"]		  = 50;
	m["/="]		  = 51;
	m[":"]		  = 52;
	m[";"]		  = 53;
	m["?"]		  = 54;
	m["["]		  = 55;
	m["]"]		  = 56;
	m["^"]		  = 57;
	m["^="]		  = 58;
	m["{"]		  = 59;
	m["|"]		  = 60;
	m["||"]		  = 61;
	m["|="]		  = 62;
	m["}"]		  = 63;
	m["~"]		  = 64;
	m["+"]		  = 65;
	m["++"]		  = 66;
	m["+="]		  = 67;
	m["<"]		  = 68;
	m["<<"]		  = 69;
	m["<<="]	  = 70;
	m["<="]		  = 71;
	m["="]		  = 72;
	m["=="]		  = 73;
	m[">"]		  = 74;
	m[">="]		  = 75;
	m[">>"]		  = 76;
	m[">>="]	  = 77;
	m["\""]		  = 78;
}

bool is(int x) {
	for(auto i : now)
		if(i.first <= x && x <= i.second)
			return true;
	return false;
}

void Analysis()
{
	string prog;
	read_prog(prog);
	/* 骚年们 请开始你们的表演 */
    /********* Begin *********/
    string str = prog;
    map<string, string> patterns{
		// {"0-HEADERS", "<\\S+>"},
		{"1-COMMENTS", "(\\/\\/[^\n]*)|(\\/\\*(\\s|.)*?\\*\\/)"},
		{"2-KEYWORDS", "(\\bauto\\b)|(\\bbreak\\b)|(\\bcase\\b)|(\\bchar\\b)|(\\bconst\\b)|(\\bcontinue\\b)|(\\bdefault\\b)|(\\bdo\\b)|(\\bdouble\\b)|(\\belse\\b)|(\\benum\\b)|(\\bextern\\b)|(\\bfloat\\b)|(\\bfor\\b)|(\\bgoto\\b)|(\\bif\\b)|(\\bint\\b)|(\\blong\\b)|(\\bregister\\b)|(\\breturn\\b)|(\\bshort\\b)|(\\bsigned\\b)|(\\bsizeof\\b)|(\\bstatic\\b)|(\\bstruct\\b)|(\\bswitch\\b)|(\\btypedef\\b)|(\\bunion\\b)|(\\bunsigned\\b)|(\\bvoid\\b)|(\\bvolatile\\b)|(\\bwhile\\b)"},
		{"3-NUMBERS", "-?[0-9]+(\\.[0-9]+)?((E|e)?(\\+|-)?[0-9]+)?"},
		{"4-OPERATORS", "<=|>=|==|\\+\\+|&&|&|\\^|\\|\\||\\||\\*|\\+|\\/|=|!="},
		{"5-INDUSTRY", "\\.|\\(|\\)|\\{|\\}|\\[|\\]|\"|'|;|,"},
		{"6-FORMAT", "%[doxucsfeg]"},
		{"7-IDENTIFIERS", "[a-z|A-Z|_]+"},
	};
	init();
	map<size_t, pair<string, string>> matches;
	// vector<pair<string, string>> matches;

	for(auto pat = patterns.begin(); pat != patterns.end(); ++pat) {
		// cout << pat->first << '\t' << pat->second << endl;
		regex r(pat->second);
		auto  words_begin = sregex_iterator(str.begin(), str.end(), r);
		auto  words_end	  = sregex_iterator();

		for(auto it = words_begin; it != words_end; ++it) {
			if(is(it->position()))
				continue;
			matches[it->position()] = make_pair(pat->first, it->str());
			now.push_back(make_pair(it->position(), it->position() + it->str().size() - 1));
			// cout << it->position() << " " << it->str() << endl;
		}
	}
	int	 i	   = 0;
	auto match = matches.begin();
	while(match != matches.end()) {
		// cout << match->first << endl;
		if(match->second.first == "7-IDENTIFIERS" || match->second.first == "6-FORMAT")
			cout << ++i << ": <" << match->second.second << "," << 81 << ">";
		else if(match->second.first == "3-NUMBERS")
			cout << ++i << ": <" << match->second.second << "," << 80 << ">";
		else if(match->second.first == "1-COMMENTS")
			cout << ++i << ": <" << match->second.second << "," << 79 << ">";
		else
			cout << ++i << ": <" << match->second.second << "," << m[match->second.second] << ">";
		if(++match != matches.end())
			cout << "\n";
	}
    /********* End *********/

}