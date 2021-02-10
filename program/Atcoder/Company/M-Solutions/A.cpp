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
    for(int i = 0; i< 10; i++){
        if(n < 400 + 200*(i+1)){
            cout << 8-i << endl;
            return 0;
        }
    }
    return 0;
}