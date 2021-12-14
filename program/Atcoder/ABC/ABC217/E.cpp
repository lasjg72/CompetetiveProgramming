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
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> q2;
    queue<int> q1;
    while(q--){
        int c;
        cin >> c;
        if(c == 1){
            int x;
            cin >> x;
            q1.push(x);
        }else if(c == 2){
            if(q2.size() == 0){
                cout << q1.front() << endl;
                q1.pop();
            }else{
                cout << q2.top() << endl;
                q2.pop();
            }

        }else if(c == 3){
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    return 0;
}