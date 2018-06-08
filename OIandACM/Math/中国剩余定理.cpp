int extended_gcd(int a, int b, int &x, int &y){
	int ret;
	if(!b){
		x = 1;
		y = 0;
		return a;
	}
	ret = extended_gcd(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ret;
}
//ret == gcd(a, b)
//x * a + y * b == gcd(a, b)

// 利用exgcd求逆元
int inv(int a, int b){
	int x, y;
	extended_gcd(a, b, x, y);
	return x;
}
//若ax≡1 (mod b)，则称x是a关于模b的逆元，常记做a^-1

// Chinese Remainder Theorem
int CRT(const int a[], const int m[], int n){
	int M = 1;
	int ret = 0;
	for(int i = 1; i <= n; i++)
		M *= m[i];
	for(int i = 1; i <= n; i++){
		int Mi = M / m[i];
		int ti = inv(Mi, m[i]);
		ret = (ret + a[i] * Mi * ti) % M;
	}
	return ret;
}
//对于同余方程组x≡ai(mod mi) (i=1...n)，若mi两两互质，则x在mod M下有唯一解。这里M=m1m2...mn
