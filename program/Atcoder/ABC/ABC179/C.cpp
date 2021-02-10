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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> dp(n+10, 0);
    dp[2] = 1;
    for(int i = 3; i < n+1; i++){
        const auto &res = prime_factorize(i-1);
        int num= 1;
        for(auto p: res){
            num *= (p.second+1);
        }
        dp[i] = dp[i-1] + num;
    }
    cout << dp[n] << endl;
    return 0;
}