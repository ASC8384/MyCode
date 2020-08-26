# 【扩域/佩尔方程】2017 ACM/ICPC 沈阳 F - Heron and His Triangle

## 大意

给你一个$n$，求$t$，满足$t \ge n$，使得边长为 $t-1, t, t+1$ 的三角形**面积**为整数。

## 题解

因为数据过大，指数增长，记得开 `__int128` 。

### 法一扩域：

比赛时搞了这种。

1. 由海伦公式得：$ A={\sqrt {s(s-a)(s-b)(s-c)}}, {\displaystyle s={\frac {a+b+c}{2}}} $，显然$ A = {\sqrt {(\frac {3t}{2})(\frac {t-2}{2})(\frac {t}{2})(\frac {t+2}{2})}}$

2. 两边平方，$x=\frac{t}{2},A^2 = 3\times{(x-1)} \times{(x+1)}\times{x^2}$

3. 显然，只有$x^2-1=3y^2$时，式子里的所有未知量都为整数

4. 设一个复数域（可能说法有误），$\mathbb{Z}(a,b)=a+bi, i=\sqrt{3}$，然后定义函数$Z_{x,y} = (x-\sqrt{3}y)(x+\sqrt{3}y)=x^2-3y^2$

5. 显然，$(x-\sqrt{3}y)(x+\sqrt{3}y)=1=x^2-3y^2$

6. 由肉眼观察，当$x=2,y=1$时，$1=x^2-3y^2=Z_{2,1}$

7. $Z_{x,y} \times Z_{a,b} = (x^2-3y^2) \times (a^2-3b^2) = Z_{(x,y)(a,b)} = Z_{ax+3by,ay+bx} = a^2x^2+9b^2y^2-3a^2y^2-3b^2x^2$

8. $1 = Z_{x,y} \times Z_{2,1}=Z_{(x+\sqrt{3}y)(2+\sqrt{3})}=Z_{2x+3y,2y+x}$，即$(2x+3y, 2y+x)$满足原式，可以用$(2,1)$一项项~~用矩阵加速幂~~推出来，答案就是$2x$

### 法二佩尔：

针对：$x^2-dy^2=1$

1. 用肉眼观察出特解$x_1=1,y_1=0$

2. ~~矩阵~~直接推，证明有空加（设$a=x_1-y_1\sqrt{D}$给出方程$x^2-Dy^2=T$，取$d=D,T=1$）

$
\left\{
\begin{array}{c}
    x_{n-1}x_1+dy_{n-1}y_1=x_n \\
    x_{n-1}y_1+y_{n-1}x_1=y_n
\end{array}
\right.
$

## 代码

``` cpp

/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-26 14:36:21
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 233 + 9;
const ll  mod  = 1e9 + 7;

void prt(__int128 x) {
	if(x > 9)
		prt(x / 10);
	putchar(x % 10 + '0');
}

void read(__int128 &X) {
	X		= 0;
	int	 w	= 0;
	char ch = 0;
	while(!isdigit(ch)) {
		w |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	if(w)
		X = -X;
}

__int128 xx[size], yy[size];

void init() {
	xx[1] = 2;
	yy[1] = 1;
	for(int i = 2; i <= 233; i++) {
		xx[i] = xx[i - 1] * 2 + yy[i - 1] * 3;
		yy[i] = xx[i - 1] + yy[i - 1] * 2;
	}
	for(int i = 1; i <= 233; i++)
		xx[i] <<= 1;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	init();

	int t = 1;
	// cin >> t;
	scanf("%d", &t);
	while(t--) {
		__int128 n;
		read(n);
		for(int i = 1; i <= 233; i++) {
			if(xx[i] >= n) {
				prt(xx[i]);
				putchar('\n');
				break;
			}
		}
	}

	return 0;
}

```
