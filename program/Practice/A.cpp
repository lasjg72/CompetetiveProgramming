#include <iostream>
#include <fstream>
#include <vector>
#include "Include.hpp"
using namespace std;
using ll = long long;
extern int tmp;

int main()
{
    const char *filename = "test.txt";
    int x = 1, y = 2;
    vector<int> a;
    cout << calc(x, tmp) << endl;
    {
        ifstream ifs(filename);
        if(!ifs){
            cout << "file error" << endl;
        }
        string tmp;
        while(!ifs.eof()){
            getline(ifs, tmp);
            a.push_back(stoi(tmp));
        }
    }
    for(auto b : a){
        cout << b << endl;
    }
#if 0
    printf("Hello\n");
#else
    printf("World\n");
#endif
    return 0;
}