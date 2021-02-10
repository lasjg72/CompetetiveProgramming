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
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if((y[i]-y[j])/(x[i]-x[j]) <= 1 && (y[i]-y[j])/(x[i]-x[j]) >= -1){
                ans++;
                // cout << "-------------" << endl;
                // cout << x[i] << " " << y[i] << endl;
                // cout << x[j] << " " << y[j] << endl;
                // cout << (y[i]-y[j])/(x[i]-x[j]) << endl;
                // cout << "-------------" << endl;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}