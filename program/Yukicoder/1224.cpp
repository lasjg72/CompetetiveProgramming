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
    double a, b;
    cin >> a >> b;
    double tmp = a/b;
    cout << tmp << endl;
    cout <<  (a/b) * b << endl;
    cout << 0.222222*9 << endl;
    if(tmp * b != a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}