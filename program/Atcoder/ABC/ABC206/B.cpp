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
    for(int i = 1; i <= n; i++){
        if(i*(i+1)/2 >= n){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}