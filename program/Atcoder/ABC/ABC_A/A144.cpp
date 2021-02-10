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
    if(0 <= a && a <= 9 && 0 <= b && b <= 9){
        cout << a * b << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}