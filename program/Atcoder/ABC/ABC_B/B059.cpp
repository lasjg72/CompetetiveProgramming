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
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()){
        cout << "GREATER" << endl;
        return 0;
    }else if(a.size() < b.size()){
        cout << "LESS" << endl;
        return 0;
    }else{
        for(ll i = 0; i < a.size(); i++){
            int A = a[i]-'0';
            int B = b[i]-'0';
            if(A > B){
                cout << "GREATER" << endl;
                return 0;
            }else if(A < B){
                cout << "LESS" << endl;
                return 0;
            }else{
                continue;
            }
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}