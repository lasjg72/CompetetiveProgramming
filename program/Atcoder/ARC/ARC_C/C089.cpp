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
    vector<int> t(n+1, 0), x(n+1, 0), y(n+1, 0);
    for(int i = 1; i<= n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        int t_gap = t[i+1]-t[i];
        int x_gap = abs(x[i+1]-x[i]);
        int y_gap = abs(y[i+1]-y[i]);
        if(t_gap < x_gap + y_gap){
            cout << "No" << endl;
            return 0;
        }else{
            if(t_gap % 2 != (x_gap + y_gap)%2){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}