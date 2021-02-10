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
    int a, b;
    cin >> a >> b;
    char c = '0'+a;
    cout << c << endl;
    char d = '0'+b;
    string A, B;
    for(int i =0; i<b;i++){
        A.push_back(c);
    }
    for(int i = 0; i<a;i++){
        B.push_back(d);
    }

    cout << min(A, B) << endl;
    
    if(a < b){
        for(int i =0; i< b;i++){
            cout << a;
        }
        cout << endl;
    }else{
        for(int i =0; i< a;i++){
            cout << b;
        }
        cout << endl;
    }
    
    return 0;
}