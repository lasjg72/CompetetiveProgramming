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

int dp[1005][1005];

int main()
{
    int A, B;
    cin >> A >> B;
    vector<int> a(A), b(B);
    ll ta = 0, tb = 0;
    for(int i = 0; i < A; i++) {
        cin >> a[i];
        ta += a[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> b[i];
        tb += b[i];
    }
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(i == 0) dp[0][j] = b[B-j]-dp[0][j-1];
            else if(j == 0) dp[i][0] = a[A-i]-dp[i-1][0];
            else dp[i][j] = max(a[A-i]-dp[i-1][j], b[B-j]-dp[i][j-1]);
        }
    }
    cout << (dp[A][B]+ta+tb)/2 << endl;
    return 0;
}