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
    vector<pair<int, int>> a, b;
    //vector<int> b(n);
    bool x1 = false;
    bool y1 = false;
    bool g = false;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x == 1 || x == -1){
            x1 = true;
            if(y == 2*n || y == -1){
                y1 = true;
            }
            if(x == -1 || y == -1) continue;
        }
        if(y == 2*n || y == -1){
            y1 = true;
            if(y == -1) continue;
        }
        if(x != -1 && y != -1 && x >= y){
            // cout << "No" << endl;
            // return 0;
            g = true;
        }
        a.push_back({x, i});
        b.push_back({y, i});
    }
    
    if(!x1 || !y1){
        // cout << "No" << endl;
        // //cout << "ko1" << endl;
        // return 0;
        g = true;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        //cout << "a.first: " << a[i].first << endl;
        //cout << "a.second: " << a[i].second << endl;
        //cout << "b.first: " << b[i].first << endl;
        //cout << "b.second: " << b[i].second << endl;
        if(a[i].first == -1 || b[i].first == -1) continue;
        if(a[i].second != b[i].second){
            // cout << "No" << endl;
            // //cout << "ko2" << endl;
            // return 0;
            g = true;
        }
    }
    if(g){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}