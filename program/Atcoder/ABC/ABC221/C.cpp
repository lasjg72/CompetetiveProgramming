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
    vector<int> n;
    for(int i = 0; i < s.size(); i++){
        n.push_back(s[i]-'0');
    }
    sort(n.rbegin(), n.rend());
    bool tmp = true;
    string t1 = "", t2 = "";
    if(s.size()%2 == 0){
        for(int i = 0; i < s.size(); i++){
            if(tmp){
                t1 += n[i]+'0';
                tmp = false;
            }else{
                t2 += n[i]+'0';
                tmp = true;
            }
        }
        int ans1 = stoi(t1);
        int ans2 = stoi(t2);
        cout << ans1*ans2 << endl;
    }else{
        for(int i = 0; i < s.size()-1; i++){
            if(tmp){
                t1 += n[i]+'0';
                tmp = false;
            }else{
                t2 += n[i]+'0';
                tmp = true;
            }
        }
        string tmp2 = t1;
        tmp2 += n[s.size()-1]+'0';
        int now1 = stoi(tmp2);
        int now2 = stoi(t2);
        int ans1 = now1*now2;
        string tmp3 = t2;
        tmp3 += n[s.size()-1]+'0';
        now1 = stoi(tmp3);
        now2 = stoi(t1);
        int ans2 = now1*now2;
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}