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
    string n;
    cin >> n;
    int m = 0;
    for(int i = 0; i < 3; i++){
        m=0;
        for(int j = 0; j < n.length(); j++){
            m += n[j]-'0';
        }
        n = to_string(m);
    }
    cout << m << endl;
    return 0;
}