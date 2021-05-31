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

ll npow(ll n, ll x){
    if(x == 0) return 1;
    if(x%2 == 0) return npow(n, x/2)*npow(n, x/2);
    else return npow(n, x-1)*n;
}

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

using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> res(1000008, 0);
    for(int i = 0; i < n; i++){
        ll tmp = a[i];
        vector<P> x;
        for(int j = 2; j*j <= tmp; j++){
            int num = 0;
            while(tmp%j == 0){
                num++;
                tmp /= j;
            }
            x.emplace_back(j, num);
        }
        if(tmp != 1) x.emplace_back(tmp, 1);
        for(P p : x){
            res[p.first] = max(p.second, res[p.first]);
        }
    }
    mint now = 1;
    for(int i = 1; i <= 1000000; i++){
        if(res[i] != 0){
            now *= npow(i, res[i]);
        }
    }
    mint ans = 0;
    for(int i = 0; i < n; i++){
         ans = (ans+now/(mint)a[i]);
    }
    cout << ans << endl;
    return 0;
}