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
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i].second >> t[i].first;
    }
    sort(t.begin(), t.end());
    ll tot = 0;
    for(int i = 0; i < n; i++){
        tot += t[i].second;
        if(tot > t[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}