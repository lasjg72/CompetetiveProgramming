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
    string n;
    cin >> n;
    int a = 0;
    map<int, int> div;
    for(int i = 0; i < n.size(); i++){
        int x = n[i]-'0';
        a += x;
        div[x%3]++;
    }
    a %= 3;
    if(a == 0){
        cout << 0 << endl;
        return 0;
    }else if(a == 1){
        if(div[1] > 0){
            if(n.size() != 1){
                cout << 1 << endl;
                return 0;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else if(div[2] > 1){
            if(n.size() != 2){
                cout << 2 << endl;
                return 0;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            cout << -1 << endl;
            return 0;
        }
    }else if(a == 2){
        if(div[2] > 0){
            if(n.size() != 1){
            cout << 1 << endl;
            return 0;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else if(div[1] > 1){
            if(n.size() != 2){
            cout << 2 << endl;
            return 0;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}