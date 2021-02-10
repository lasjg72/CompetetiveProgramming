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
    string s;
    cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    while(next_permutation(v.begin(), v.end())){
        string tmp = "";
        for(int i = 0; i < n; i++){
            tmp += s[v[i]];
        }
        if(s != tmp){
            reverse(tmp.begin(), tmp.end());
            if(s != tmp){
                reverse(tmp.begin(), tmp.end());
                cout << tmp << endl;
                return 0;
            }
        }
    }
    cout << "None" << endl;
    return 0;
}