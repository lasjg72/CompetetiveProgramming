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

// template <typename T>
// struct RMQ {
//     const T INF = numeric_limits<T>::max();
//     int n;         // 葉の数
//     vector<T> dat; // 完全二分木の配列
//     RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
//         int x = 1;
//         while (n_ > x) {
//             x *= 2;
//         }
//         n = x;
//     }
//     void update(int i, T x) {
//         i += n - 1;
//         dat[i] = x;
//         while (i > 0) {
//             i = (i - 1) / 2;  // parent
//             dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
//         }
//     }
//     // the minimum element of [a,b)
//     T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
//     T query_sub(int a, int b, int k, int l, int r) {
//         if (r <= a || b <= l) {
//             return INF;
//         } else if (a <= l && r <= b) {
//             return dat[k];
//         } else {
//             T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
//             T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
//             return min(vl, vr);
//         }
//     }
// };
using P = pair<ll, ll>;

int main()
{
    int q;
    cin >> q;
    
    ll num = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    // RMQ<ll> RMQ(200005);
    while(q--){
        int p;
        cin >> p;
        if(p == 1){
            ll x;
            cin >> x;
            que.push(x-num);
        }else if(p == 2){
            ll x;
            cin >> x;
            num += x;
        }else{
            ll p = que.top(); 
            que.pop();
            cout << p+num << endl;
            //p.first += (num-p.second);
            //cout << p.first << endl;
        }
    }
    return 0;
}