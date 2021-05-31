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
    long double a, b, c;
    cin >> a >> b >> c;
    if(a+b+2*sqrt(a*b) < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}