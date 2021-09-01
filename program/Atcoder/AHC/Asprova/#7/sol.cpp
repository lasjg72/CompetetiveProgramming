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
using P = pair<int, int>;

int main()
{
    int M, S, T, L;
    cin >> M >> S >> T >> L;
    vector<vector<int>> t(M, vector<int>(S));
    vector<int> x(S), n(M);
    // P(車の間隔と作業時間の差, 車種)
    // 各車種について、作業時間と運ばれてくる間隔の差の小ささが大きい順に生産していく
    vector<P> p(M);
    vector<P> sum(M);
    for(int i = 0; i < M; i++){
        int res = 1001001001, tmp = 0;
        for(int j = 0; j < S; j++) cin >> t[i][j];
        for(int j = 0; j < S; j++){
            tmp += t[i][j];
            res = min(abs(T-t[i][j]), res);
        }
        p[i] = P(res, i);
        sum[i] = P(tmp, i);
    }
    sort(p. rbegin(), p.rend());
    sort(sum.begin(), sum.end());
    for(int i = 0; i < S; i++) cin >> x[i];
    for(int i = 0; i < M; i++) cin >> n[i];

    cout << n[sum[0].second] << endl;
    for(int i = 0; i < n[sum[0].second]; i++){
        cout << sum[0].second+1 << " ";
    }
    cout << endl;
    return 0;
}
