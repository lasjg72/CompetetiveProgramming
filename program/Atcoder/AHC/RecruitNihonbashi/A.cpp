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

int n, m, K;

// ll score(vector<ll> a){
//     ll res = 0;
//     int n = a.size();
//     for(int i = 0; i < n; i++){
        
//     }
//     return res;
// }

using P = pair<int, int>;

int main()
{
    cin >> n >> m >> K;
    vector<P> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<P> ans;
    //vector<P> l;
    deque<P> l, r;
    for(int i = 0; i < n; i++){
        if(a[i].first > 50) r.push_back(a[i]);
        else l.push_back(a[i]);
    }
    while(m > 0){
        //cout << m << endl;
        // for(P p : l){
        //     cout << "lp: " << p.first << " " << p.second << endl;
        // }
        // cout << "----" << endl;
        // for(P p : r){
        //     cout << "rp: " << p.first << " " << p.second << endl;
        // }
        if(r.size() == 0){
            //cout << "r0: " << endl;
            int tmp = l.back().first, num = 0;
            while(tmp <= 50){
                tmp += l.back().first;
                num++;
            }
            if(num > m){
                ans.push_back({l[0].second, l[0].second});
                l[0].first = l[0].first+l[0].first;
                if(l[0].first >= 50){
                    r.push_back({l[0].first, l[0].second});
                    l.pop_front();
                    sort(r.begin(), r.end());
                }else{
                    sort(l.begin(), l.end());
                }
                m--;
            }else{
                for(int i = 0; i < num; i++){
                    ans.push_back({l.back().second, l.back().second});
                    m--;
                }
                l.back().first = tmp%K;
                if(l.back().first >= 50){
                    r.push_back({l.back().first, l.back().second});
                    l.pop_back();
                    sort(r.begin(), r.end());
                }else{
                    sort(l.begin(), l.end());
                }
            }
        }else if(l.size() == 0){
            //cout << "l0 "<< endl;
            ans.push_back({r.back().second, r.back().second});
            P p = r.back();
            r.pop_back();
            p.first = (p.first+p.first)%K;
            l.push_back({p.first, p.second});
            sort(l.begin(), l.end());
            m--;
        }else{
            //cout << "other " << endl;
            int pos = 0;
            while(l[pos].first+r.back().first < 100 && pos < l.size()){
                pos++;
            }
            if(pos >= l.size()){
                if(m >= 2){
                    //cout << "ko" << endl;
                    ans.push_back({r.back().second, r.back().second});
                    if((r.back().first+r.back().first)%K <= 50){
                        l.push_back({(r.back().first+r.back().first)%K, r.back().second});
                        r.pop_back();
                        sort(l.begin(), l.end());   
                    }else{
                        r.back().first = (r.back().first+r.back().first)%K;
                    }
                    m--;
                    //cout << "ko2" << endl;
                    if(r.size() == 0){
                        continue;
                    }
                    P now = r.back();
                    ans.push_back({l[0].second, now.second});
                    r.pop_back();
                    r.push_back({l[0].first+now.first, now.second});
                    sort(r.begin(), r.end());   
                    m--;
                }else{
                    ans.push_back({r.front().second, r.front().second});
                    m--;
                    if((r.front().first+r.front().first)%K <= 50){
                        l.push_back({(r.front().first+r.front().first)%K, r.front().second});
                        r.pop_front();
                        sort(l.begin(), l.end());   
                    }else{
                        r.push_back({(r.front().first+r.front().first)%K, r.front().second});
                        r.pop_front();
                        sort(r.begin(), r.end());
                    }
                }
            }else{
                ans.push_back({r.back().second, l[pos].second});     
                m--;           
                if((l[pos].first+r.back().first)%K <= 50){
                    l.push_back({(l[pos].first+r.back().first)%K, l[pos].second});
                    r.pop_back();
                    sort(l.begin(), l.end());
                }else{
                    r.push_back({(l[pos].first+r.back().first)%K, l[pos].second});
                    r.pop_back();
                    sort(r.begin(), r.end());
                }
            }
        }
    }
    for(P p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}