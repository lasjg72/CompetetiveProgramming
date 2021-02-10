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
    int n, d;
    cin >> n >> d;
    ll to = 0;
    vector<pair<ll, ll>> s(n);
    for(int i = 0; i< n; i++){
        cin >> s[i].first;
    }
    for(int i = 0; i< n; i++){
        cin >> s[i].second;
        to += s[i].second;
    }
    sort(s.begin(), s.end());
    ll t = 0, dis = 0;

    // while(1){
    //     t++;
    //     for(int i = 0; i< n; i++){
    //         s[i].first += s[i].second;
    //         dis += s[i].second;
    //     }
    //     for(int i = 0; i< n-1; i++){
    //         if(s[i].first == s[i+1].first){
    //             s[i].second += s[i+1].second;
    //             s[i+1].first = 0;
    //             s[i+1].second = 0;
    //         }
    //     }
    //     if(dis >= d) break;
    // }
    if(d % to == 0){
        t = d / to;
    }else{
        t = d / to + 1;
    }
    cout << t << endl;
    return 0;
}