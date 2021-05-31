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
    int n, k;
    cin >> n >> k;
    vector<double> w(n), p(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> p[i];
    }
    double l = 0, r = 100;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2;
        //cout << "mid: " << mid << endl;
        vector<double> val(n);
        for(int j = 0; j < n; j++){
            val[j] = w[j]*(p[j]-mid);
        }
        sort(val.rbegin(), val.rend());
        double tmp = 0;
        for(int j = 0; j < k; j++){
            tmp += val[j];
        }
        if(tmp >= 0) l = mid;
        else r = mid;
    }
    printf("%.8f\n", (l+r)/2);
    return 0;
}