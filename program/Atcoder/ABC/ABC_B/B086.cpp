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
    string tmp = a+b;
    int num = stoi(tmp);

    for(int i = 1; i*i < 100200; i++){
        if(num == i*i){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}