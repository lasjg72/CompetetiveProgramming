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
    vector<ll> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%4 == 0){
            mp[4]++;
        }else if(a[i]%2 == 0){
            mp[2]++;
        }else mp[1]++;
    }
    if(mp[2] == 0 && mp[4]+1 >= mp[1]){
        cout << "Yes" << endl;
    }else if(mp[4] >= mp[1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}