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
    double d, t, s;
    //int d, t, s;
    cin >> d >> t >> s;
    if(d/s > t){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}