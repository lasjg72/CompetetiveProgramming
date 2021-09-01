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
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    map<string, int> mp;
    mp[s1]++;
    mp[s2]++;
    mp[s3]++;
    mp[s4]++;
    if(mp["H"] == 1 && mp["2B"] == 1 && mp["3B"] == 1 && mp["HR"] == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}