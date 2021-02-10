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
    string s;
    cin >> s;
    if(s[0] == s[2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}