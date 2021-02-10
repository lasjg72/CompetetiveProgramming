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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2){
        cout << 0 << endl;
    }else if(x1+y1 == x2+y2 || x1-y1 == x2-y2 || abs(x1-x2)+abs(y1-y2) <= 3){
        cout << 1 << endl;
        return 0;
    }else{
        int tmp = x1-x2;
        int tmpy1 = y1 + tmp;
        int tmpy2 = y1 - tmp;
        if(abs(x1-x2)+abs(y1-y2)<=6 ||abs(tmpy1-y2) <= 3 ||abs(tmpy2-y2) <= 3 || (x1-x2) % 2 == (y1-y2) % 2){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }
    return 0;
}