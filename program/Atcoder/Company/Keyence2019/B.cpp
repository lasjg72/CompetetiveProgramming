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
    string s;
    cin >> s;
    int n = s.size();
    string t = "keyence";
    int pos = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string tmp;
            tmp += s.substr(0, i);
            tmp += s.substr(min(j+1, n-1), n-(j-i+1));
            if(tmp == t){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}