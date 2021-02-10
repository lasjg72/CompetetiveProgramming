#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    map<string, int> s;
    for(int i =0; i < n ;i++){
        cin >> t;
        s[t]++;
    }
    int maxv = 0;
    for(const auto& x: s){
        int v = x.second;
        if(v > maxv) maxv = v;
    }
    for(auto it = s.begin(); it != s.end(); it++){
        if(it->second == maxv){
            cout << it->first << endl;
        }
    }

    return 0;
}