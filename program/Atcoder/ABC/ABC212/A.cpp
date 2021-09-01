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
    if(a > 0 && b == 0){
        cout << "Gold" << endl;
    }else if(a == 0 && b > 0){
        cout << "Silver" << endl;
    }else{
        cout << "Alloy" << endl;
    }
    return 0;
}