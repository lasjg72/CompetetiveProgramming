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
    int n;
    cin >> n;
    multiset<double> v;
    for(int i = 0; i < n; i++){
        double a;
        cin >> a;
        v.insert(a);
    }
    for(int i = 0; i < n-1; i++){
        double x, y;
        x = *v.begin();
        //cout << "x: " << x << endl;
        v.erase(v.find(x));
        y = *v.begin();
        //cout << "y: " << y << endl;
        v.erase(v.find(y));
        double z = (x+y)/2;
        v.insert(z);
    }
    // cout << "size: " << v.size() << endl;
    cout << *v.begin() << endl;
    return 0;
}