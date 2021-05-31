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
    int n;
    cin >> n;
    if(n == 0){
        cout << "Yes" << endl;
        return 0;
    }
    while(n%10 == 0) n /= 10;
    string now = to_string(n);
    int size = now.size();
    for(int i = 0; i < size; i++){
        if(now.size()-i-1 < 0) continue;
        if(now[i] != now[now.size()-i-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}