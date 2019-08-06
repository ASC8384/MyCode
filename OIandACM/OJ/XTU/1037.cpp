#include <iostream>
#include <string>
#include <vector>

int main()
{
	int k;
	std::string s;
	std::vector<char> stk;
	//char s[2333];
	//scanf("%d", &k);
	std::cin >> k;

	for(int i = 0; i < k; i++){
		//scanf("%s", s);
		std::cin >> s;
		for(unsigned int j = 0; j < s.size(); j++){
			if(stk.empty()){
				stk.push_back(s[j]);
				continue;
			}
			if(stk.back() != s[j]){
				stk.push_back(s[j]);
			}else{
				stk.pop_back();
			}
		}
		if(stk.empty())
			//printf("Yes\n");
            std::cout << "Yes" << std::endl;
		else
			//printf("No\n");
            std::cout << "No" << std::endl;
		stk.clear();
	}
	return 0;
}