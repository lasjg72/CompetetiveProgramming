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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    map<int , int> ans;

        for(ll i = 1; i*i <= n; i++){
            
            for(ll j = 1; j*j <= n; j++){
                
                for(ll k = 1; k*k <= n; k++){
                    
                    ll tmp = (i+j+k)*(i+j+k);
                    int p = tmp-i*j-i*k-j*k;
                    
                    if(p > 0){
                        if(i == j && j == k){
                            ans[p]++;
                            continue;
                        }else if(i == j && j != k){
                            ans[p]++;
                            continue;
                        }
                        else if(i!= j && j == k){
                            ans[p]++;
                            continue;
                        }
                        else if(i == k && i != j){
                            ans[p]++;
                            continue;
                        }else if(i!=k && j != k && i != j){
                            ans[p]++;
                            continue;
                        }
                    }
                }
            }
        }

    for(int i = 1; i <= n; i ++){
        cout << ans[i] << endl;
    }

    return 0;
}