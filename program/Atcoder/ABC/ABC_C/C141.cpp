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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n, 0);
    for(int i = 0; i < q; i++){
        int b;
        cin >> b;
        b--;
        a[b]++;
    }
    for(int i = 0; i < n; i++){
        if(k > q){
            cout << "Yes" << endl;
            continue; 
        }else if(a[i] > q-k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
   return 0;
}