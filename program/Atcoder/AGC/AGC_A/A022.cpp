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
    string s;
    cin >> s;
    map<char, int> a;
    if(s.length() < 26){
        for(int i = 0; i < s.length(); i++){
            a[s[i]]++;
        }
        for(int i = 0; i < 26; i++){
            if(a['a' + i] == 0){
                char b = 'a' + i;
                cout << s + b << endl;
                return 0;
            }
        }
    }else{
        for(int i = s.length()-1; i > 0; i--){
            if(s[i] > s[i-1]){
                for(int j = 0; j <= i-1; j++){
                    a[s[j]]++;
                }

                for(int j = 0; j < 26; j++){
                    if(a['a' + j] == 0 && 'a' + j > s[i-1]){
                        char b = 'a' + j;
                        for(int k = 0; k < i-1; k++){
                            cout << s[k];
                        }
                        cout << b << endl;
                        return 0;
                    }
                }
            }
        }
        cout << -1 << endl;
    }
    return 0;
}
