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
    string s, t;
    cin >> s >> t;
    string S(3, 'a'), T(3, 'a');
    for(int i =0; i<3;i++){
        S[i] = tolower(s[i]);
        T[i] = tolower(t[i]);
    }
    if(s == t){
        cout << "same" << endl;
        return 0;
    }else if(S == T){
        cout << "case-insensitive" << endl;
        return 0;
    }else{
        cout << "different" << endl;
        return 0;
    }
    return 0;
}