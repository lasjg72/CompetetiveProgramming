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
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){   
            for(int k = 0; k < n; k++){
                //cout << "ko" << endl;
                if(k == i || k == j) continue;
                if(x[i] == x[j] && x[j] == x[k]){
                    cout << "Yes" << endl;
                    return 0;
                }
                if(y[i] == y[j] && y[j] == y[k]){
                    cout << "Yes" << endl;
                    return 0;
                }
                double l = y[k] - y[i];
                //cout << "l: " << l << endl;
                double r1 = y[j] - y[i];
                double r2 = x[k] - x[i];
                double r3 = x[j] - x[i];
                if(r3 == 0) continue;
                double r = r1 * r2 / r3;
                //cout << "r: " << r << endl;
                if(l == r){
                    cout << "Yes" << endl;
                    
                    return 0;
                } 
            }
        }
    }
    cout << "No" << endl;
    return 0;
}