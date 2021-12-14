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
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    map<P, int> mp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].second == p[j].second){
                if(p[i].first <= p[j].first){
                    mp[{p[i].first, p[j].first}]++;
                    
                    //cout << "add: " << p[i].first << " " << p[j].first << endl;
                }else{
                    mp[{p[j].first, p[i].first}]++;
                    //cout << "add: " << p[j].first << " " << p[i].first << endl;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].second == p[j].second){
                if(p[i].first <= p[j].first){
                    ans += mp[{p[i].first, p[j].first}]-1;
                    //cout << "mp: " << mp[{p[i].first, p[j].first}]-1 << endl;
                }else{
                    ans += mp[{p[j].first, p[i].first}]-1;
                    //cout << "mp: " << mp[{p[j].first, p[i].first}]-1 << endl;
                }
            }
        }
    }
    cout << ans/2 << endl;
    return 0;
}