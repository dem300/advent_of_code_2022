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
    string a, b, c;
    int score = 0;
    while (cin >> a >> b >> c){
        for (char& car:a){
            if (b.find(car) != string::npos && c.find(car) != string::npos){                
                if (islower(car))
                    score+= car - 96;
                else
                    score+= car - 38;
                break;
            }
        }
    }
    cout << score << endl;
}