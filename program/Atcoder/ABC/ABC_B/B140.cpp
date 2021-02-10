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
    vector<int> a(n), b(n), c(n-1);
    for(int i = 0; i< n; i++) cin >> a[i];
    for(int i = 0; i< n; i++) cin >> b[i];
    for(int i = 0; i< n-1; i++) cin >> c[i];

    int ans = 0;
    for(int i = 0; i< n; i++){
        ans += b[a[i]-1];
        if(i != 0 && a[i-1]+1 == a[i]){
            ans += c[a[i-1]-1];
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}