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
    for(int i = 11; i <= 55555; i += 10){
        bool ok = true;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0) {
                ok = false;
                break;
            }
        }
        if(ok){
            cout << i << " ";
            n--;
            if(n == 0){
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}