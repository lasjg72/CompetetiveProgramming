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
    int len = s.size();
    map<char, int> num;
    vector<char> can;
    vector<int> res;
    ll ans = 0;
    char ko = '1';
    for(int i = len-1; i >= 0; i--){
        if(i-1 >= 0){
            if(s[i-1] == s[i]){
                if(ko == '1' || ko == s[i]){
                    ko = s[i];
                }else{
                    int tmp = num[s[i]];
                    num.erase(begin(num), end(num));
                    num[s[i]] = tmp;
                    ko = s[i];
                }
                int tmp = num[s[i]];
                num.erase(begin(num), end(num));
                num[s[i]] = tmp;
                ans += (len-1-i)-num[s[i]];
                num[s[i]]+= (len-1-i)-num[s[i]];
                //cout << "num: " << num[s[i]] << endl;
                //cout << (len-1-i)-num[s[i]] << endl;
            }
        }
        num[s[i]]++;
        //cout << "saishuu" << num[s[i]] << endl;
    }
    cout << ans << endl;
    return 0;
}