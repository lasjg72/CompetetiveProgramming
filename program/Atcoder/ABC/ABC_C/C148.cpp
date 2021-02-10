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

int main()
{
    ll a, b;
    cin >> a >> b;
    map<ll, ll> da, db;

    int i = 1;
    int tmp = a;
    while(i*i < a){
        i++;
        while(tmp % i == 0){
            da[i]++;
            tmp /= i;
        }
    }
    if(tmp != 1) da[tmp]++;

    i = 1;
    tmp = b;
    while(i*i < b){
        i++;
        while(tmp % i == 0){
            db[i]++;
            tmp /= i;
        }
    }
    if(tmp != 1) db[tmp]++;

    ll mx = max(a,b);
    if(mx < 4){
        cout << a * b << endl;
        return 0;
    }
    for(int i = 2; i<= mx; i++){
        if(da[i] != db[i]){
            if(da[i] > db[i]){
                for(int j = 0; j < da[i]-db[i]; j++){
                    b *= i;
                }
            }else{
                for(int j = 0; j < db[i]-da[i]; j++){
                    a *= i;
                }
            }
        }
    }
    cout << a << endl;
    return 0;
}