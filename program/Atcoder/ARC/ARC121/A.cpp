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
    vector<P> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<pair<int, P>> x1(4);
    x1[0].first = abs(x[n-1].first-x[0].first);
    if(x[n-1].second > x[0].second){
        x1[0].second = {x[0].second, x[n-1].second};
    }else{
        x1[0].second = {x[n-1].second, x[0].second};
    }
    if(abs(x[n-1].first-x[1].first) > abs(x[n-2].first-x[0].first)){
        x1[1].first = abs(x[n-1].first-x[1].first);
        if(x[n-1].second > x[1].second){
            x1[1].second = {x[1].second, x[n-1].second};
        }else{
            x1[1].second = {x[n-1].second, x[1].second};
        }
    }else{
        x1[1].first = abs(x[n-2].first-x[0].first);
        if(x[n-2].second > x[0].second){
            x1[1].second = {x[0].second, x[n-2].second};
        }else{
            x1[1].second = {x[n-2].second, x[0].second};
        }
    }
    x1[2].first = abs(y[n-1].first-y[0].first);
    if(y[n-1].second > y[0].second){
        x1[2].second = {y[0].second, y[n-1].second};
    }else{
        x1[2].second = {y[n-1].second, y[0].second};
    }
    if(abs(y[n-1].first-y[1].first) > abs(y[n-2].first-y[0].first)){
        x1[3].first = abs(y[n-1].first-y[1].first);
        if(y[n-1].second > y[1].second){
            x1[3].second = {y[1].second, y[n-1].second};
        }else{
            x1[3].second = {y[n-1].second, y[1].second};
        }
    }else{
        x1[3].first = abs(y[n-2].first-y[0].first);
        if(y[n-2].second > y[0].second){
            x1[3].second = {y[0].second, y[n-2].second};
        }else{
            x1[3].second = {y[n-2].second, y[0].second};
        }
    }
    sort(x1.rbegin(), x1.rend());
    // for(int i = 0; i < 4; i++){
    //     cout << x1[i].first << endl;
    // }
    if(x1[0].second == x1[1].second){
        //cout << "ko" << endl;
        cout << x1[2].first << endl;
    }else{
        cout << x1[1].first << endl;
    }
    return 0;
}