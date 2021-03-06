#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} comb(100005);

int main()
{
    int t;
    int n, a, b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> a >> b;
        mint ans = 0;
        if(a >= b){
            if(3 * a > n){
                int ca = (n - a + 1);
                int cb = n - b + 1;
                int nb = n - a - b + 1;
                if(nb < 0){
                    cout << 0 << endl;
                    continue;
                }
                mint numb = nb * cb * 2 - 1;
                ans = numb * ca * ca;
                cout << ans << endl;
            }else{
                //まず通常
                int ca = (n - a + 1);
                int cb = n - b + 1;
                int na = a * a;
                int nb = n - a - b + 1;
                if(nb < 0){
                    cout << 0 << endl;
                    continue;
                }
                mint numb = nb * cb * 2 - 1;
                ans += numb * na * ca;
                //両端に小さい正方形がくる場合
                int na2 = n - (a * 2) - a + 1;
                int nb2 = a - b + 1;
                mint numb2 = nb2 * 2 * nb 
            }
        }else{
            if(3 * b > n){

            }else{

            }
        }
    }
    return 0;
}