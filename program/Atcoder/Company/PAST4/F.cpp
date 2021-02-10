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
    map<string, int> x;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        x[tmp]++;
    }
    priority_queue<pair<int, string>> q;
    for(auto tmp : x){
        q.push({tmp.second, tmp.first});
    }
    pair<int, string> pre, now, next;
    for(int i = 0; i < k-1; i++){
        pair<int, string> tmp = q.top();
        q.pop();
        if(i == k-2){
            pre = tmp;
        }
    }
    now = q.top(); q.pop();
    if(!q.empty()){
        next = q.top(); q.pop();
        if(pre.first != now.first && now.first != next.first){
            cout << now.second << endl;
        }else{
            cout << "AMBIGUOUS" << endl;
        }
    }else{
        if(pre.first != now.first){
            cout << now.second << endl;
        }else{
            cout << "AMBIGUOUS" << endl;
        }
    }
    return 0;
}