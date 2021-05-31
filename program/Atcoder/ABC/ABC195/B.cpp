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
    double a, b;
    double w;
    cin >> a >> b >> w;
    w *= 1000;
    int mi = 1001001001;
    int mx = -1;
    for(int i = 1; i <= 1000000; i++){
        double now = w / i;
        if(now >= a && now <= b){
            mi = min(mi, i);
            mx = max(mx, i);
        }
    }
    if(mi == 1001001001 || mx == -1){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << mi << " " << mx << endl;
    }
    return 0;
}