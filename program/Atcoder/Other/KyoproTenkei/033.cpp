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
    int h, w;
    cin >> h >> w;
    if(h == 1 || w == 1){
        cout << h*w << endl;
    }else{
        cout << ceil((double)h/2)*ceil((double)w/2) << endl;
    }
    return 0;
}