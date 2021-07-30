/**********************************************************************
*                             ex_gcd.cpp                             *
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		ex_gcd.cpp
** Description	扩展欧几里得算法
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
**********************************************************************/

int ex_gcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int ret, tmp;
    ret = ex_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

//ax + by = gcd(x, y)
typedef long long ll;
ll ex_gcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll ret, tmp;
    ret = ex_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}
