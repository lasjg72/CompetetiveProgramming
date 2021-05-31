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
    ll n;
    cin >> n;
    for(int i = 1; i <= 3500; i++){
        for(int j = 1; j <= 3500; j++){
            if(4*i*j-n*i-n*j != 0 && (n*i*j)%(4*i*j-n*i-n*j) == 0){
                if((n*i*j)/(4*i*j-n*i-n*j) < 0 ) continue;
                cout << i << " " << j << " " << (n*i*j)/(4*i*j-n*i-n*j) << endl;
                return 0;
            }
        }
    }
    return 0;
}