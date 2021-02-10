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
    int k;
    cin >> s >> k;
    set<string> a;
    int size = s.size();
    int mx = min(5, size);
    for(int i = 0; i< s.size(); i++){
        string tmp;
        for(int j = 0; j < mx; j++){
            if(i+j>=s.size()) break;
            tmp += s[i+j];
            a.insert(tmp);
        }
    }
    auto itr = a.begin();
    for(int i = 1; i< k; i++){
        //cout << *itr << endl;
        itr++;
    }
    cout << *itr << endl;
    return 0;
}