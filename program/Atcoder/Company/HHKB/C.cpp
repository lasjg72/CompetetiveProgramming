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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    map<int, int> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        m[p[i]]++;
        if(ans != p[i]) cout << ans << endl;
        else{
            while(m[ans] != 0){
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}