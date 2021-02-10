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
    int n, m, t;
    cin >> n >> m >> t;
    int ma = n;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }
    int now=0;
    for(int i = 0; i < m; i++){
        n-=(a[i]-now);
        if(n<=0){
            cout << "No" << endl;
            return 0;
        }
        n+=b[i]-a[i];
        if(n > ma){
            n = ma;
        }
        now=b[i];
        //cout << n << endl;
    }
    n=n-(t-now);
    //cout << n << endl;
    if(n<=0){
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    return 0;
}