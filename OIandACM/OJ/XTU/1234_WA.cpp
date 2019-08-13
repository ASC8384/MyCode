#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x; 
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

//string a = "auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while";
string s;

int main()
{
	int k = init();

	while(k--){
		// scanf("%s", s);
		cin >> s;
		if(isdigit(s[0]) || (s[0] != '_' && !isalpha(s[0]))){
			printf("No\n");
		}else{
			if(s == "auto" || s == "break" || s == "case" || s == "char" || s == "const" || s == "continue" 
					|| s == "default" || s == "do" || s == "double" || s == "else" || s == "enum" || s == "extern" 
					|| s == "float" || s == "for" || s == "goto" || s == "if" || s == "int" || s == "long" 
					|| s == "register" || s == "return" || s == "short" || s == "signed" || s == "sizeof" 
					|| s == "static" || s == "struct" || s == "switch" || s == "typedef" || s == "union"
					|| s == "unsigned" || s == "void" 
					|| s == "volatile" || s == "while" )
 //blog.csdn.net/qq_39322743/article/details/78825632)
			//if(a.find(s) != string::npos)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}