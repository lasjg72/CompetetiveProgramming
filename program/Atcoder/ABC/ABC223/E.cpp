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
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> num;
    num.push_back(a);
    num.push_back(b);
    num.push_back(c);
    sort(num.begin(), num.end());
    ll mi = num[0];
    ll edge = ceil(sqrt((double)mi));
    if(x*y < a+b+c){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 1; i <= edge; i++){
        if(mi%i != 0) continue;
        ll other = mi/i;
        if(other < x){
            ll nx = x-other;
            if(nx*edge == num[1] && x*(y-edge) == num[2]){
                cout << "Yes" << endl;
                return 0;
            }else if(nx*edge == num[2] && x*(y-edge) == num[1]){
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(other < y){
            ll ny = y-other;
            if(ny*x == num[1] && other*(x-edge) == num[2]){
                cout << "Yes" << endl;
                return 0;
            }else if(ny*x == num[2] && other*(x-edge) == num[1]){
                cout << "Yes" << endl;
                return 0;
            }
        }   
    }
    cout << "No" << endl;
    return 0;
}