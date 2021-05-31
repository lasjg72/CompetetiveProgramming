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
    string s, t;
    cin >> s >> t;
    map<char, int> num1, num2;
    vector<int> cnt1(s.size()+1, 0), cnt2(s.size()+1, 0);
    for(int i = 0; i < s.size(); i++){
        num1[s[i]]++;
        num2[t[i]]++;
    }
    for(int i = 0; i < s.size(); i++){
        cnt1[num1[s[i]]]++;
        cnt2[num2[t[i]]]++;
    }
    for(int i = 0; i < s.size(); i++){
        if(cnt1[i] != cnt2[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}