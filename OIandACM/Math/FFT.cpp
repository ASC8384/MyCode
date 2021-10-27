const double PI = acos(-1.0);
struct Complex {
	double x, y;
	Complex(double _x = 0.0, double _y = 0.0) {
		x = _x;
		y = _y;
	}
	Complex operator-(const Complex &b) const {
		return Complex(x - b.x, y - b.y);
	}
	Complex operator+(const Complex &b) const {
		return Complex(x + b.x, y + b.y);
	}
	Complex operator*(const Complex &b) const {
		return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
	}
};

/*
*进行FFT和IFFT前的反置变换
*位置i和i的二进制反转后的位置互换
*len必须为2的幂
*/
void change(Complex a[], int len) {
	for(int i = 0, j = 0; i < len; i++) {
		if(i > j)
			swap(a[i], a[j]);
		for(int l = len >> 1; (j ^= l) < l; l >>= 1)
			;
	}
}

/*
*做FFT
*len必须是2^k形式
*on == 1时是DFT，on == -1时是IDFT
*/
void fft(Complex y[], int len, int on) {
	change(y, len);
	for(int h = 2; h <= len; h <<= 1) {
		Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for(int j = 0; j < len; j += h) {
			Complex w(1, 0);
			for(int k = j; k < j + h / 2; k++) {
				Complex u	 = y[k];
				Complex t	 = w * y[k + h / 2];
				y[k]		 = u + t;
				y[k + h / 2] = u - t;
				w			 = w * wn;
			}
		}
	}
	if(on == -1) {
		for(int i = 0; i < len; i++) {
			y[i].x /= len;
		}
	}
}

const int MAXN = 3000000 + 9;
Complex	  a[MAXN], b[MAXN];
int		  ans[MAXN];

void FFT(void) {
	int len = 1;
	while(len < lena + lenb)
		len <<= 1;
	fft(a, len, 1);
	fft(b, len, 1);
	for(int i = 0; i < len; i++)
		a[i] = a[i] * b[i];
	fft(a, len, -1);
	for(int i = 1; i <= len; i++)
		ans[i] = (int)(a[i].x + 0.5);
}