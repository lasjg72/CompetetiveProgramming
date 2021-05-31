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

vector<int> d(int n){
    vector<int> v;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            v.push_back(i);
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}

int main()
{
    int n;
    cin >> n;
    // (1, 75) (3, 5, 5) (3, 25) (15, 5) 
    map<int, int> mp;
    for(int i = 2; i <= n; i++){
        vector<int> v = d(i);
        for(int j: v){
            mp[j]++;
        }
    }
    vector<int> num(101, 0);
    vector<int> a = {75, 25, 15, 5, 3};
    // for(int i = 2; i <= 100; i++){
    //     //cout << "i: " << i << " mp: " << mp[i] << endl;
        
    //     for(int j: a){
    //         if(mp[i]+1 >= j) {
    //             num[j]++;
    //             break;
    //         }
    //     }
    // }
    int ans = 0;
    mp[1] = 1;
    for(int i = 2; i <= n; i++){
        
        for(int j = 2; j <= mp[i]+1; j++){
            
            for(int i2 = i+1; i2 <= n; i2++){
                
                for(int j2 = 2; j2 <= mp[i2]+1; j2++){
                    
                    for(int i3 = i2+1; i3 <= n; i3++){
                        
                        for(int j3 = 2; j3 <= mp[i3]+1; j3++){
                            if(j*j2*j3 == 75) {
                                //cout << "i: " << i << " j: " << j << " i2: " << i2 << " j2: " << j2 << " i3: " << i3 << " j3: " << j3 << endl;
                                ans++;
                            }
                        }
                    }       
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= mp[i]+1; j++){
            for(int i2 = i+1; i2 <= n; i2++){
                for(int j2 = 2; j2 <= mp[i2]+1; j2++){
                    if(j*j2 == 75) ans++;       
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= mp[i]+1; j++){
            if(j == 75) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}