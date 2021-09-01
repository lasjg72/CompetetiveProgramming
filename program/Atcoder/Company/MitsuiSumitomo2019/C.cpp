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
    while(x%10 >= 5){
        x -= 105;
    }
    while(x%10 >= 4){
        x -= 104;
    }
    while(x%10 >= 3){
        x -= 103;
    }
    while(x%10 >= 2){
        x -= 102;
    }
    while(x%10 >= 1){
        x -= 101;
    }
    while(x%100 >= 10){
        x -= 210;
    }
    if(x < 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}
