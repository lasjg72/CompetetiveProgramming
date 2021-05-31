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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    multiset<int> d;
    for(int i = 0; i < n; i++){
        auto p = d.lower_bound(a[i]);
        if(p == d.begin()){
            d.insert(a[i]);
        }else{
            auto it = d.lower_bound(a[i]);
            it--;
            d.erase(it);
            d.insert(a[i]);
        }
    }
    cout << d.size() << endl;
    return 0;
}