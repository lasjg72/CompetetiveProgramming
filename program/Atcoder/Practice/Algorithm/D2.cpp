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
    int n;
    cin >> n;
    vector<string> s(5);
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];

    int j =1, i=0;
    string ans(n,0);
    while(j <= n){
        int L = 4*j-2-1;
        int C = 4*j-1-1;
        int R = 4*j-1;
        if(s[0][L] == '#' && s[0][C] == '#' && s[0][R] == '#'){
            if(s[1][L] == '#'){ //0, 5, 6, 8, 9
                if(s[3][L] == '#'){ //0, 6, 8
                    if(s[1][R] != '#') ans[i] = '6';
                    else{
                        if(s[2][C] == '#') ans[i] = '8';
                        else ans[i] = '0';
                    }
                }else if(s[3][R] == '#'){ //5, 9
                    if(s[1][R]=='#') ans[i] = '9';
                    else ans[i] = '5';
                }
            }else if(s[1][R] == '#'){ //2, 3, 7
                if(s[3][L] == '#') ans[i] = '2';
                else{
                    if(s[2][L] == '#') ans[i] = '3';
                    else ans[i] = '7';
                }
            }
        }else if(s[0][L] == '#' && s[0][C] != '#' && s[0][R] == '#'){
            ans[i] = '4';
        }else if(s[0][L] != '#' && s[0][C] == '#' && s[0][R] != '#'){
            ans[i] = '1';
        }
        j++;
        i++;
    }
    cout << ans << endl;
    return 0;
}