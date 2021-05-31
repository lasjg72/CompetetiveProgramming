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

//int dp[1001001001];

int main()
{
    int n;
    cin >> n;
    if(n%2) cout << 1 << endl;
    else{
        cout << n/2+1 << endl;
    }
    return 0;
}