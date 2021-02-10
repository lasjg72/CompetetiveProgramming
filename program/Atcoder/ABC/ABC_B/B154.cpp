#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i =0; i< s.size(); i++){
        s[i] = 'x';
    }
    cout << s << endl;
    return 0;
}