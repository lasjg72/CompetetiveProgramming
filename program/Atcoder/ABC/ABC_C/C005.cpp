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
    int t, n, m;
    cin >> t >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    if(n < m){
        cout << "no" << endl;
        return 0;
    }  
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int num = 0;
    for(int i = 0; i < m; i++){
        while(num < n){
            // cout << b[i] << endl;
            // cout << a[num] << endl;
            if(b[i]-a[num] >= 0 && b[i]-a[num] <= t){
                if(i != m-1) num++;
                break;
            }else{
                num++;
            }
        }
    }
    //cout << num << endl;
    if(num == n){
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
    return 0;
}