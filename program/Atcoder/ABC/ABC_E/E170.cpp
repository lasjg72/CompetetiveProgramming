#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    int n, q, c, d;
    cin >> n >> q;
    vector<int> a(n,0), b(n,0), tmp(q);
    vector<multiset<int>> s(200005);
    multiset<int> maxs;
    int x;

    for(int i =0; i < n; i++){
        cin >> a[i] >> b[i];
        if(s[b[i]].size() != 0){
            x = *s[b[i]].rbegin();
            maxs.erase(maxs.find(x));
        }
        s[b[i]].insert(a[i]);
        x = *s[b[i]].rbegin();
        maxs.insert(x);
    }
    
    int ans;
    for(int i = 0; i< q; i++){
        cin >> c >> d;


        x = *s[b[c-1]].rbegin();
        maxs.erase(maxs.find(x));


        if(s[d].size() != 0){
            x = *s[d].rbegin();
            maxs.erase(maxs.find(x));
        }


        s[b[c-1]].erase(a[c-1]);
        s[d].insert(a[c-1]);


        if(s[b[c-1]].size() != 0){
            x = *s[b[c-1]].rbegin();
            maxs.insert(x);
        }
        x = *s[d].rbegin();
        maxs.insert(x);


        b[c-1] = d;

        ans = *maxs.begin();
        tmp[i] = ans;
    }

    for(int i =0;i<q ; i++){
        cout << tmp[i] << endl;
    }

    return 0;
}