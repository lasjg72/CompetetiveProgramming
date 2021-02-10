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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

vector<ll> prime;
map<ll, int> q;

// void div_func(ll num){
//     prime.push_back(1);
//     q[1]++;
//     //ll tmp = num;
//     for(int i = 2; i*i <= num; i++){
//         if(num % i != 0) continue;
//         prime.push_back(i);
//         while(1){
//             if(num % i == 0){
//                 num = num / i;
//                 q[i]++;
//             }else break;
//         }
//     }
//     if(num != 1){
//         prime.push_back(num);
//         q[num]++;
//     }
// }

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    //cout << "g: " << g << endl;
    //div_func(g);
    auto pf = prime_factorize(g);
    cout << pf.size()+1 << endl;
    return 0;
}