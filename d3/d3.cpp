#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    string input, a, b;
    int score = 0;   

    while (cin >> input){ 
        int size = input.size();
        a = input.substr(0, size/2);
        b = input.substr(size/2);
        for (char& c:a){
            if (b.find(c) != string::npos){
                if (islower(c))
                    score+= c - 96;
                else
                    score+= c - 38;
                break;
            }
        }
    }
    cout << score << endl;
}