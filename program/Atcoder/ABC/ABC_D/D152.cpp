#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;
using ll = long long;

pair<int, int> func(int x){
    int b = x%10;
    int a = 0;
    while(x){
        a = x;
        x /= 10;
    }
    return {a, b};
}

int main()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> freq;
    for(int i = 1; i<=n; i++){
        pair<int, int> p = func(i);
        freq[p]++;
    }
    ll ans = 0;
    for(int i = 1; i<=n;i++){
        pair<int, int> q = func(i);
        ans += freq[{q.second, q.first}];
    }
    cout << ans << endl;
    return 0;
}