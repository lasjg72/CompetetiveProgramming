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
    map<char, int> a;
    for(int i = 0; i < s.size(); i++){
        a[s[i]]++;
        if(a[s[i]] > 1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}