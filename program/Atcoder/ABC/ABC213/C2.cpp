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
    vector<int> res = a;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for(int i = 0; i < a.size(); i++){
        a[i] = lower_bound(res.begin(), res.end(), a[i])-res.begin()+1;
    }
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
    for(int i = 0; i < n; i++) printf("%d %d\n", a[i], b[i]);
    return 0;
}