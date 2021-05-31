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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> t;
    if(s[0] == '0') t.push_back(0);
    for(int i = 0; i < n; i++){
        int now = s[i]-'0';
        int num = 0;
        while(1){
            num++;
            //cout << "num: " << num << endl;
            if(i < n && i+1 < n && s[i+1]-'0' == now){i++;}
            else {
                t.push_back(num);
                break;
            }
        }
    }
    if(s.back() == '0') t.push_back(0);

    // for(int i : t){
    //     cout << "num:" << i << endl;
    // }
    vector<int> sum((int)t.size()+1, 0);
    for(int i = 0; i < (int)t.size(); i++){
        sum[i+1] = sum[i] + t[i];
        //cout << "sum:" << sum[i+1] << endl; 
    }
    int ans = 0;
    //if(s[0] == '1'){
        for(int left = 0; left < (int)sum.size(); left += 2){
            int right = left + 2*k+1;
            if(right >= (int)sum.size()){
                right = sum.size()-1;
            }
            ans = max(ans, sum[right]-sum[left]);
        }
    // }else{
    //     for(int left = 0; left < (int)sum.size(); left += 2){
    //         int right = left + 2*k;
    //         if(right >= (int)sum.size()){
    //             right = sum.size()-1;
    //         }
    //         ans = max(ans, sum[right]-sum[left]);
    //     }
    // }
    cout << ans << endl;
    return 0;
}