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
    if(a > b){
        if(a < b + 3){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if(b < a + 3){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
