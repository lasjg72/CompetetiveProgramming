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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    if((n-1)%(k-1) != 0){
        ans += (n-1)/(k-1)+1;
    }else ans += (n-1)/(k-1);

    cout << ans << endl;
    return 0;
}