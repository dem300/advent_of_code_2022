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
    string input, e1, e2;
    int a1, a2, b1, b2;
    int score = 0;   

    while (cin >> input){ 

        e1 = input.substr(0, input.find(","));
        e2 = input.substr(input.find(",") + 1);
        a1 = stoi(e1.substr(0, e1.find("-")));
        a2 = stoi(e1.substr(e1.find("-") + 1));
        b1 = stoi(e2.substr(0, e2.find("-")));
        b2 = stoi(e2.substr(e2.find("-") + 1));

        if ((a1 <= b1 && a2 >= b2) || (a1 >= b1 && a2 <= b2)) score+=1;
    }
    cout << score << endl;
}