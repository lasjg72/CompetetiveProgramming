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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        c[i] = a[i]-b[i];
    }
    sort(c.begin(), c.end());
    int ans = 0;
    if(c[0] >= 0){
        cout << ans << endl;
    }else{
        int pos1 = 0, pos2 = n-1;
        ans++;
        while(c[pos1] < 0){
            if(c[pos2] < 0){
                ans = -1;
                break;
            }
            if(abs(c[pos1]) <= abs(c[pos2])){
                c[pos2] += c[pos1];
                c[pos1] = 0;
                pos1++; 
                ans++;
            }else{
                c[pos1] += c[pos2];
                c[pos2] = 0;
                pos2--;
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}