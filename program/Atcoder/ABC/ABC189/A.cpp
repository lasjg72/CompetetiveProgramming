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
    char a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << "Won" << endl;
    }else{
        cout << "Lost" << endl;
    }
    return 0;
}