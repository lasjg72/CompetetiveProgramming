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
    set<int> s;
    map<int, int> num;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        num[a[i]]++;
        s.insert(a[i]);
    }
    // for(int i = 0; i < n; i++){
    //     cout << "a[i]: " << a[i] << endl;
    //     cout << num[a[i]] << endl;
    // }
    int ev = 0;
    for(int i = 0; i < n; i++){
        if(num[a[i]] == 0) continue;
        // cout << a[i] << endl;
        // cout << "num: " << num[a[i]] << endl;
        if(num[a[i]]%2) num[a[i]] = 0;
        else{
            num[a[i]] = 0;
            ev++;
        }
    }
    //cout << ev << endl;
    if(ev%2 == 0){
        cout << s.size() << endl;
    }else{
        cout << s.size()-1 << endl;
    }
    return 0;
}