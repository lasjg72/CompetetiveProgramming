#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) continue;
        else cout << "error" << endl;
        return 0;
    }
    cout << 2 * stoi(s) << endl;
    return 0;
}