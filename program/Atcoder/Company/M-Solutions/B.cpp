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
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    for(int i = 0; i < k; i++){
        if(a >= b){
            b *= 2;
        }else if(b >= c){
            c *= 2;
        }
    }
    if(a < b && b < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}