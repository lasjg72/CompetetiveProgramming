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
    string s;
    cin >> n >> s;
    if(s.length() % 2 == 1){
        cout << "No" << endl;
        return 0;
    }else{
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()/2 + i]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}