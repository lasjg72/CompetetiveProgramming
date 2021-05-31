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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int num = 0;
    while(q--){
        //cout << "------" << endl;
        int t, x, y;
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            x--; y--;
            swap(a[(x-num+n)%n], a[(y-num+n)%n]);
            // for(int i = 0; i < n; i++){
            //     cout << a[(i-num+n)%n] << " ";
            // }
            // cout << endl;
        }else if(t == 2){
            cin >> x >> y;
            num += 1;
            num %= n;
            // cout << "num: " << num << endl;
            // for(int i = 0; i < n; i++){
            //     cout << (i-num+n)%n << " ";
            // }
            // cout << endl;
            // for(int i = 0; i < n; i++){
            //     cout << a[(i-num+n)%n] << " ";
            // }
            // cout << endl;
        }else{
            cin >> x >> y;
            x--;
            cout << a[(x-num+n)%n] << endl;
        }
    }
    return 0;
}