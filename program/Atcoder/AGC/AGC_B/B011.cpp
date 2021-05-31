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
    vector<ll> a(n), sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        sum[i+1] = sum[i] + a[i];
    }
    int num;
    for(int i = 0; i < n; i++){
        if(sum[i] *2 < a[i]) num = i;
    }
    cout << n-num << endl;
    return 0;
}