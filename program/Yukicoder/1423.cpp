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
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a + b <= c){
            if(a >= b){
                for(int i = 0; i <= (c-a)/b; i++){
                    b *= (i+2);
                    if(a+b > c){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else b /= (i+2);
                }
            }else{
                for(int i = 0; i <= (c-b)/a; i++){
                    a *= (i+2);
                    if(a+b > c){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else a /= (i+2);
                }
            }
        }else if(b + c <= a){
            if(b >= c){
                for(int i = 0; i <= (a-b)/c; i++){
                    c *= (i+2);
                    if(b+c > a){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else c /= (i+2);
                }
            }else{
                for(int i = 0; i <= (a-c)/b; i++){
                    b *= (i+2);
                    if(b+c > a){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else b /= (i+2);
                }
            }
        }else if(c + a <= b){
            if(a >= c){
                for(int i = 0; i <= (b-a)/c; i++){
                    c *= (i+2);
                    if(c + a > b){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else c /= (i+2);
                }
            }else{
                for(int i = 0; i <= (b-c)/a; i++){
                    a *= (i+2);
                    if(c + a > b){
                        cout << a << " " << b << " " << c << endl;
                        return 0;            
                    }else a /= (i+2);
                }
            }
        }else{
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }
    return 0;
}