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
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    queue<int> A, B, C;
    
    for(int i = 0; i < n; i++) A.push(a[i]);
    for(int i = 0; i < n; i++) B.push(b[i]);
    for(int i = 0; i < n; i++) C.push(c[i]);

    int ans = 0;
    while(!C.empty() && !B.empty() && !A.empty()){
        int na = A.front();
        int nb = B.front();
        //cout << "na: " << na << " nb: " << nb << endl;
        if(na < nb){
            int nc = C.front(); C.pop();
            //cout << "nc: " << nc << endl;
            if(nb < nc){
                ans++;
                A.pop();
                B.pop();
            }else{
                continue;
            }
        }else{
            B.pop();
        }
    }
    cout << ans << endl;
    return 0;
}