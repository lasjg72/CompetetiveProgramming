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
    int q;
    cin >> q;
    vector<int> a, b;
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            a.push_back(x);
        }else if(t == 2){
            b.push_back(x);
        }else{
            if(x <= a.size()){
                cout << a[a.size()-x] << endl;
            }else{
                cout << b[x-a.size()-1] << endl;
            }
        }
    }
    return 0;
}