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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<string, int> mp;
    mp[s1]++;
    mp[s2]++;
    mp[s3]++;
    if(mp["ABC"] != 1){
        cout << "ABC" << endl;
    }else if(mp["ARC"] != 1){
        cout << "ARC" << endl;
    }else if(mp["AGC"] != 1){
        cout << "AGC" << endl;
    }else if(mp["AHC"] != 1){
        cout << "AHC" << endl;
    }
    return 0;
}