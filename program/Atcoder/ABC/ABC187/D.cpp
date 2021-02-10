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

int main()
{
    // int n;
    // cin >> n;
    // vector<ll> a(n), b(n);
    // vector<pair<ll, ll>> ab(n); //firstにその街で演説した時の高橋氏の獲得票数を、secondに演説しなかった時の青木氏の票数を
    // ll numA = 0; //青木氏が得る最大票数
    // for(int i = 0; i < n; i++){
    //     cin >> a[i] >> b[i];
    //     ab[i] = {a[i]+b[i], a[i]};
    //     numA += a[i];
    // }
    // sort(ab.begin(), ab.end(), greater<pair<ll, ll>>()); //どの街から演説すると高橋氏の獲得票数が多くなるかを求める
    // ll ans = 0, num = 0;
    // for(int i = 0; i < n; i++){
    //     numA -= ab[i].second; //街iで演説することで青木氏の獲得票数がa[i]だけ減る
    //     num += ab[i].first; //街iで演説することで高橋氏の獲得票数がa[i]+b[i]だけ増える
    //     ans++;
    //     if(numA < num){
    //         cout << ans << endl;
    //         return 0;
    //     }
    // }
    // cout << n << endl;

    int n;
    cin >> n;
    vector<ll> a(n), b(n), x(n);
    ll X = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        X -= a[i];
        x[i] = 2 * a[i] + b[i];
    }
    sort(x.begin(), x.end(), greater<ll>());
    for(int i = 0; i < n; i++){
        X += x[i];

        if(X > 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}