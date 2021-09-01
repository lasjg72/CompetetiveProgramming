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
    int h, w, n;
    cin >> h >> w >> n;
    //vector<pair<int, P>> a(n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        int p, q;
        cin >> a[i] >> b[i];
        //cin >> p >> q;
        
        // a[i] = {p, {q, i}};
    }

    vector<P> na(n), nb(n);

    for(int i = 0; i < n; i++){
        na[i].first = a[i];
        nb[i].first = b[i];
        na[i].second = i+1;
        nb[i].second = i+1;
    }
    
    sort(na.begin(), na.end());
    sort(nb.begin(), nb.end());
    int apos = 1, bpos = 1;
    for(int i = 0; i < n; i++){
        if(i+1 != n && na[i+1].first == na[i].first){
            na[i].first = apos;
        }else{
            na[i].first = apos;
            apos++;
        }
        if(i+1 != n && nb[i+1].first == nb[i].first){
            nb[i].first = bpos;
        }else{
            nb[i].first = bpos;
            bpos++;
        }
    }

    for(int i = 0; i < n; i++){
        swap(na[i].first, na[i].second);
        swap(nb[i].first, nb[i].second);
    }

    sort(na.begin(), na.end());
    sort(nb.begin(), nb.end());
    
    for(int i = 0; i < n; i++){
        cout << na[i].second << " " << nb[i].second << endl;
    }
    // sort(a.begin(), a.end());
    // for(int i = 0; i < n; i++){
    //     a[i].first = i+1;
    // }
    // for(int i = 0; i < n; i++){
    //     swap(a[i].first, a[i].second.first);

    // }

    // sort(a.begin(), a.end());
    // for(int i = 0; i < n; i++){
    //     a[i].first = i+1;
    // }
    // for(int i = 0; i < n; i++){
    //     swap(a[i].first, a[i].second.second);
    // }

    // sort(a.begin(), a.end());
    // for(int i = 0; i < n; i++){
    //     cout << a[i].second.first << " " << a[i].second.second << endl;
    // }
    return 0;
}