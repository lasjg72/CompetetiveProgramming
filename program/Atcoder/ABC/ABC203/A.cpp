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
    int a, b, c;
    cin >> a >> b >> c;
    if(a != b && b != c && a != c){
        cout << 0 << endl;
    }else if(a == b){
        cout << c << endl;
    }else if(b == c){
        cout << a << endl;
    }else if(a == c){
        cout << b << endl;
    }
    return 0;
}
