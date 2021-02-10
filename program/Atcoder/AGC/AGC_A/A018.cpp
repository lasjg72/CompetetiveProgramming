#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main()
{
    int n, k, mx= 0;
    cin >> n >> k;
    int gc;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == k){
            cout << "POSSIBLE" << endl;
            return 0;
        }
        mx = max(mx, a[i]);
    }
    if(n != 1) gc = gcd(a[0], a[1]);
    else if(n==1 && k % a[0] == 0){
        cout << "POSSIBLE" << endl;
        return 0;
    }else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if(mx < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        gc = gcd(gc, a[i]);
    }

    if(k % gc == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}