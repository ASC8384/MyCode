#include <bits/stdc++.h>
using namespace std;
 
class Bigint
{
public :
    //constructor
    Bigint(long long = 0);
    Bigint(const string &);
    Bigint(const char *str) { *this = string(str); }
 
    //assignment operators
    Bigint &operator=(long long num) { return *this = Bigint(num); }
    Bigint &operator=(const string &str) { return *this = Bigint(str); }
    Bigint &operator=(const char *str) { return *this = Bigint(str); }
 
    //relatiional operators
    bool operator<(const Bigint &obj) const { return cmp(obj) < 0; }
    bool operator>(const Bigint &obj) const { return cmp(obj) > 0; }
    bool operator<=(const Bigint &obj) const { return cmp(obj) <= 0; }
    bool operator>=(const Bigint &obj) const { return cmp(obj) >= 0; }
    bool operator==(const Bigint &obj) const { return cmp(obj) == 0; }
    bool operator!=(const Bigint &obj) const { return cmp(obj) != 0; }
 
    //arithmetic operators
    Bigint operator+() const { return *this; }
    Bigint operator-() const { return Bigint(-sign_, val_); }
    Bigint operator+(const Bigint &) const;
    Bigint operator-(const Bigint &) const;
    Bigint operator*(const Bigint &) const;
    Bigint operator/(const Bigint &) const;
    Bigint operator%(const Bigint &) const;
 
    //compound assignment operators
    Bigint &operator+=(const Bigint &obj) { return *this = *this + obj; }
    Bigint &operator-=(const Bigint &obj) { return *this = *this - obj; }
    Bigint &operator*=(const Bigint &obj) { return *this = *this * obj; }
    Bigint &operator/=(const Bigint &obj) { return *this = *this / obj; }
    Bigint &operator%=(const Bigint &obj) { return *this = *this % obj; }
 
    //increment and decrement operators
    Bigint &operator++() { return *this += 1; }
    Bigint &operator--() { return *this -= 1; }
    Bigint operator++(int);
    Bigint operator--(int);
 
    //input and output
    friend istream &operator>>(istream &, Bigint &);
    friend ostream &operator<<(ostream &, const Bigint &);
 
protected :
    enum div_type { division, remainder };
    enum cmp_type { with_sign, without_sign };
    static const int base_ = (int)1e4;
    static const int width_ = 4;
    Bigint(int s, const vector<int> &v) : sign_(s), val_(v) {}
    int cmp(const Bigint &, cmp_type = with_sign) const;
    Bigint &delZero();
    Bigint &add(const Bigint &);
    Bigint &sub(const Bigint &);
    Bigint &mul(const Bigint &, const Bigint &);
    Bigint &div(Bigint &, Bigint, div_type = division);
 
private :
    int sign_;
    vector<int> val_;
};
 
Bigint::Bigint(long long num) : sign_(0)
{
    if (num < 0) sign_ = -1, num = -num;
    else if (num > 0) sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    } while (num);
}
 
Bigint::Bigint(const string &str)
{
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        stringstream ss(str.substr(en, width_));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    if ((en += width_) > be)
    {
        stringstream ss(str.substr(be, en - be));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    delZero();
}
 
Bigint Bigint::operator+(const Bigint &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).add(obj) : (temp = obj).add(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this - -obj;
    else return sign_ == 0 ? obj : *this;
}
 
Bigint Bigint::operator-(const Bigint &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this + -obj;
    else return sign_ == 0 ? -obj : *this;
}
 
inline Bigint Bigint::operator*(const Bigint &obj) const
{
    Bigint temp;
    return (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.mul(*this, obj);
}
 
inline Bigint Bigint::operator/(const Bigint &obj) const
{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.div(mod, obj);
}
 
inline Bigint Bigint::operator%(const Bigint &obj) const
{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_) == 0 ? mod : temp.div(mod, obj, remainder);
}
 
inline Bigint Bigint::operator++(int)
{
    Bigint temp = *this;
    ++*this;
    return temp;
}
 
inline Bigint Bigint::operator--(int)
{
    Bigint temp = *this;
    --*this;
    return temp;
}
 
inline istream &operator>>(istream &in, Bigint &obj)
{
    string str;
    if (in >> str) obj = str;
    return in;
}
 
ostream &operator<<(ostream &out, const Bigint &obj)
{
    if (obj.sign_ == -1) cout << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(Bigint::width_) << setfill('0') << obj.val_[i];
    return out;
}
 
int Bigint::cmp(const Bigint &obj, cmp_type typ) const
{
    if (typ == with_sign && sign_ != obj.sign_) return sign_ - obj.sign_;
    int sign = typ == with_sign ? sign_ : 1;
    if (val_.size() != obj.val_.size()) return sign * (val_.size() - obj.val_.size());
    for (int i = val_.size() - 1; i >= 0; i--)
        if (val_[i] != obj.val_[i]) return sign * (val_[i] - obj.val_[i]);
    return 0;
}
 
inline Bigint &Bigint::delZero()
{
    while(val_.back() == 0 && val_.size() > 1) val_.pop_back();
    if (val_.back() == 0) sign_ = 0;
    return *this;
}
 
Bigint &Bigint::add(const Bigint &obj)
{
    int ts = val_.size(), os = obj.val_.size();
    for (int i = 0; i < os; i++) val_[i] += obj.val_[i];
    val_.push_back(0);
    for (int i = 0; i < ts; i++)
        if (val_[i] >= base_) val_[i] -= base_, ++val_[i + 1];
    return delZero();
}
 
Bigint &Bigint::sub(const Bigint &obj)
{
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
        if ((val_[i] -= obj.val_[i]) < 0) val_[i] += base_, --val_[i + 1];
    while (val_[pos] < 0) val_[pos] += base_, --val_[++pos];
    return delZero();
}
 
Bigint &Bigint::mul(const Bigint &a, const Bigint &b)
{
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++) for (int j = 0; j < bs; j++)
    {
        int x = i + j;
        val_[x] += a.val_[i] * b.val_[j];
        val_[x + 1] += val_[x] / base_;
        val_[x] %= base_;
    }
    return delZero();  
}
 
Bigint &Bigint::div(Bigint &a, Bigint b, div_type typ)
{
    int move = a.val_.size() - b.val_.size();
    val_.resize(move + 1);
    b.val_.insert(b.val_.begin(), move, 0);
    for (int i = move; i >= 0; i--)
    {
        int left = 0, right = base_;
        while (left + 1 < right)
        {
            int mid = (left + right) >> 1;
            if (a.cmp(b * Bigint(mid), without_sign) >= 0) left = mid;
            else right = mid;
        }
        val_[i] = left;
        a.sub(b * Bigint(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}
 
int main()
{
    Bigint p, n;
    int t;
    cin >> t;
    while(t--){
        cin >> p >> n;
        Bigint x = p - 1;
        Bigint ret = 1;
        n = n % (p - 1);
        Bigint tmp = 1;
        while(n >= 1){
            if(n % 2 == 1)
                ret = ret * x % p;
            x = x * x % p;
            n = n / 2;
        }
        cout << ret << endl;
    }
    return 0;
}