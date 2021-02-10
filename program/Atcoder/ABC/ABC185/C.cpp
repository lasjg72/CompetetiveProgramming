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
// const ll mod = 9.223372e+18;

// struct mint {
//   ll x; // typedef long long ll;
//   mint(ll x=0):x((x%mod+mod)%mod){}
//   mint operator-() const { return mint(-x);}
//   mint& operator+=(const mint a) {
//     if ((x += a.x) >= mod) x -= mod;
//     return *this;
//   }
//   mint& operator-=(const mint a) {
//     if ((x += mod-a.x) >= mod) x -= mod;
//     return *this;
//   }
//   mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
//   mint operator+(const mint a) const { return mint(*this) += a;}
//   mint operator-(const mint a) const { return mint(*this) -= a;}
//   mint operator*(const mint a) const { return mint(*this) *= a;}
//   mint pow(ll t) const {
//     if (!t) return 1;
//     mint a = pow(t>>1);
//     a *= a;
//     if (t&1) a *= *this;
//     return a;
//   }
 
//   // for prime mod
//   mint inv() const { return pow(mod-2);}
//   mint& operator/=(const mint a) { return *this *= a.inv();}
//   mint operator/(const mint a) const { return mint(*this) /= a;}
// };
// istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
// ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
// // combination mod prime
// // https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
// struct combination {
//   vector<mint> fact, ifact;
//   combination(int n):fact(n+1),ifact(n+1) {
//     assert(n < mod);
//     fact[0] = 1;
//     for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
//     ifact[n] = fact[n].inv();
//     for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
//   }
//   mint operator()(int n, int k) {
//     if (k < 0 || k > n) return 0;
//     return fact[n]*ifact[k]*ifact[n-k];
//   }
// } comb(100005);

// int main()
// {
//    ll L;
//    cin >> L;
//    if(L==12){
//      cout << 1 << endl;
//    }else{
//     mint ans = comb(L-1, 11);
//    cout << ans << endl;
//    }
//    return 0;
// }

// const int MAX = 510000;
// const ll MOD = 9007199254740997;

// long long fac[MAX], finv[MAX], inv[MAX];

// // テーブルを作る前処理
// void COMinit() {
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < MAX; i++){
//         fac[i] = fac[i - 1] * i % MOD;
//         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i] = finv[i - 1] * inv[i] % MOD;
//     }
// }

// // 二項係数計算
// long long COM(int n, int k){
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }

// int main() {
//     // 前処理
//     COMinit();
//     int L;
//     cin >> L;
//     // 計算例
//     //cout << COM(L-1, 11) << endl;
// }

/*
    前処理: O(MAX_N*MAX_N)
    nCk(n,k): nCk の計算。O(1)
*/
const int MAX_N = 200;         // n の最大値
vector<vector<long long>> com;  // 前計算の結果を保存
// 動的計画法で前処理
void init() {
    com.assign(MAX_N, vector<long long>(MAX_N));
    com[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_N; j++) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
        }
    }
}
// nCk を取得
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return com[n][k];
}
int main() {
    long long l;
    cin >> l;
    init();
    cout << nCk(l-1, 11) << endl;
}