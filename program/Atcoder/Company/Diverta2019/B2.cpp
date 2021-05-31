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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, int> num;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            num[{x[i]-x[j], y[i]-y[j]}]++;
            ans = max(ans, num[{x[i]-x[j], y[i]-y[j]}]);
        }
    }
    cout << n-ans << endl;
    return 0;
}