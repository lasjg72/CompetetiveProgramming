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

vector<int> compress(vector<int> a){
    int n = a.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]] = 0;
    int id = 1;
    for(auto& e : mp) e.second = id++;
    for(int i = 0; i < n; i++) a[i] = mp[a[i]];
    return a;
}

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    a = compress(a);
    b = compress(b);
    for(int i = 0; i < n; i++){
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}