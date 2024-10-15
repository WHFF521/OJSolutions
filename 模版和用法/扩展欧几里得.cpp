#define ll long long

// 扩展欧几里得
// x,y是方程ax+by=gcd(a,b)的解
//可以用来求逆元，其中x就是逆元，a是原数，b是模数
void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}