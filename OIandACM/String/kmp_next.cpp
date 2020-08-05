int kmp[size];

void getnext(string s) { // begin 0
	kmp[0] = 0;
	for(int i = 1, j = 0, n = (int)s.size(); i < n; i++) {
		while(s[i] != s[j] && j)
			j = kmp[j - 1];
		if(s[i] == s[j])
			j++;
		kmp[i] = j;
	}
}

void getnext(string s) { // begin 1
	kmp[0] = -1;
	int n  = (int)s.size();
	for(int i = 0, j = -1; i <= n;) {
		if(j == -1 || s[i] == s[j])
			kmp[++i] = ++j;
		else
			j = kmp[j];
	}
}