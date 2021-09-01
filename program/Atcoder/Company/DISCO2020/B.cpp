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
        sum[i+1] = sum[i]+a[i];
    }
    int pos = 0;
    ll tot = 1001001001001001001;
    for(int i = 0; i < n; i++){
        if(abs((sum[n]-sum[i+1])-sum[i+1]) < tot){
            tot = abs((sum[n]-sum[i+1])-sum[i+1]);
            //cout << tot << endl;
            pos = i;
        }
    }
    cout << tot << endl;
    return 0;
}