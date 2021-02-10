#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int num= 1;
    while(n > num*1000){
        num++;
    }
    cout << num*1000 - n << endl;
    return 0;
}