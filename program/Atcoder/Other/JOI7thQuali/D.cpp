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
    int m;
    cin >> m;
    vector<P> s(m);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        s[i] = {x, y};
    }
    int n;
    cin >> n;
    vector<P> ns(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        ns[i] = {x, y};
    }
    sort(s.begin(), s.end());
    sort(ns.begin(), ns.end());
    for(int i = 0; i < n; i++){
        bool ok2 = true;
        int nx = ns[i].first-s[0].first;
        int ny = ns[i].second-s[0].second;
        for(int j = 0; j < m; j++){
            bool ok = false;
            int nowx = s[i].first+nx;
            int nowy = s[i].second+ny;
            for(int k = 0; k < n; k++){
                if(k == i) continue;
                if(ns[k].first == nowx && ns[k].second == nowy){
                    ok = true;
                    break;
                }
            }
            if(ok) continue;
            else{
                ok2 = false;
                break;
            }
        }
        if(ok2) {
            cout << nx << " " << ny << endl;
            return 0;
        }else{
            continue;
        }
    }
    return 0;
}