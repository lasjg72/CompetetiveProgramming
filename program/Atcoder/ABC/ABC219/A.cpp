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
    int x;
    cin >> x;
    if(x < 40){
        cout << 40-x << endl;
    }else if(x < 70){
        cout << 70-x << endl;
    }else if(x < 90){
        cout << 90-x << endl;
    }else{
        cout << "expert" << endl;
    }
    return 0;
}