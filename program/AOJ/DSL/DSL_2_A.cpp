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

const ll INF = (1LL<<31)-1;

int n, dat[2*1000005];

void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2*n-1; i++) dat[i] = INF;
}

void update(int x, int a){
    x += n-1;
    dat[x] = a;
    while(x > 0){
        x = (x-1)/2;
        dat[x] = min(dat[2*x+1], dat[2*x+2]);
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return INF;
    
    if(a <= l && b >= r) return dat[k];
    else{
        int vl = query(a, b, 2*k+1, l, (l+r)/2);
        int vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
}

int main()
{
    int q;
    cin >> n >> q;
    init(n);
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            update(x, y);
        }else{
            cout << query(x, y+1, 0, 0, n) << endl;;
        }
    }
    return 0;
}