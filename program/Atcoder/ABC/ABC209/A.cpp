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
    int a, b;
    cin >> a >> b;
    if(b-a < 0){
        cout << 0 << endl;
    }else{
        cout << b-a+1 << endl;
    }

    return 0;
}