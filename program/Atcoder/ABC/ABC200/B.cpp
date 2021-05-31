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
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n%200 == 0){
            n /= 200;
        }else{
            string tmp = to_string(n);
            tmp += "200";
            n = stoll(tmp);
        }
    }
    cout << n << endl;
    return 0;
}