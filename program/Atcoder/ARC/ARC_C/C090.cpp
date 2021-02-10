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
    vector<int> a(n), b(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j <= i; j++){
            tmp += a[j];    
        }
        for(int k = i ; k < n; k++){
            tmp += b[k];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}