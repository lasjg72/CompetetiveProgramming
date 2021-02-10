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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(2*x > y){
        if(a > b){
            cout << abs(a-b-1) * y + x << endl;;
        }else{
            cout << abs(a-b) * y + x << endl;
        }
    }else{
        if(a > b){
            cout << abs(a-b) * 2 * x -x << endl;
        }else{
            cout << abs(a-b) * 2 * x + x << endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <tuple>
// #include <vector>
// #include <string>
// #include <queue>
// #include <cmath>
// #include <set>
// #include <map>
// #include <cassert>

// using namespace std;
// using ll = long long;

// int main()
// {
//     int a, b, x, y;
//     cin >> a >> b >> x >> y;
//     if(2*x > y){
//         cout << abs(a-b) * y + x << endl;
//     }else{
//         if(a > b){
//             cout << abs(a-b) * 2 * x -x << endl;
//         }else{
//             cout << abs(a-b) * 2 * x + x << endl;
//         }
//     }
//     return 0;
// }