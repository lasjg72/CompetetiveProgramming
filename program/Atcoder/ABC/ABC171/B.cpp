#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n,0);
    for(int i = 0; i< n; i++){
        cin >> p[i];
    }
    //cout << "--1-" << endl;
    sort(p.begin(), p.end());
    int ans = 0;
    for(int i = 0; i < k;i++){
        //cout << "---" << endl;
        ans += p[i];
    }
    cout << ans << endl;
    return 0;
}