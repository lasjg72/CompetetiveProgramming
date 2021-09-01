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
    double n;
    cin >> n;
    if(floor(n*1.08) > 206){
        cout << ":(" << endl;
    }else if(floor(n*1.08) == 206){
        cout << "so-so" << endl;
    }else if(floor(n*1.08) < 206){
        cout << "Yay!" << endl;
    }
    return 0;
}