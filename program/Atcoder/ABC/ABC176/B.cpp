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
    ll sum = 0;
    for(int i = 0; i < n.length(); i++){
        sum += n[i]-'0';
    }
    //cout << sum << endl;
    if(sum % 9 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}