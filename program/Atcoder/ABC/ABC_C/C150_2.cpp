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
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n), a(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    iota(a.begin(), a.end(), 1);
    ll pnum, qnum, num = 1;
    do{
        bool pok = true, qok = true;
        for(int i = 0; i < n; i++){
            if(a[i] != p[i]) pok = false;
            if(a[i] != q[i]) qok = false;
        }
        if(pok) pnum = num;
        if(qok) qnum = num;
        num++;
    }while(next_permutation(a.begin(), a.end()));
    cout << abs(pnum-qnum) << endl;
    return 0;
}