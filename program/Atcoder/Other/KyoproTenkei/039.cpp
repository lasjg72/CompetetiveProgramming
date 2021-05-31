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

const int INF = 1001001001;

int n, dat[2*100005-1];

void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2*n-1; i++) dat[i] = -1;
}

void update(int x, int a){
    x += n-1;
    dat[x] = a;
    while(x > 0){
        x = (x-1)/2;
        dat[x] = max(dat[2*x+1], dat[2*x+2]);
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -1;
    else if(a <= l && b >= r) return dat[k];
    else{
        int vl = query(a, b, 2*k+1, l, (l+r)/2);
        int vr = query(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return 0;
}