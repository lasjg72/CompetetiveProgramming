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
    if(n >= 42){
        cout << "AGC0" << n+1 << endl;
    }else if(n > 9){
        cout << "AGC0" << n << endl;
    }else{
        cout << "AGC00" << n << endl;
    }
    return 0;
}
