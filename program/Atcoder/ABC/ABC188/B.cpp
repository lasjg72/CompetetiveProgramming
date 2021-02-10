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
    vector<int> a(n), b(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    for(int i = 0; i< n; i++){
        cin >> b[i];
    }
    ll tot = 0;
    for(int i = 0; i < n; i++){
        tot += a[i]*b[i];
    }
    if(tot == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}