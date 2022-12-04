#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

map<string, int> points = {{"X", 1}, {"Y", 2} , {"Z", 3}};
map<string, int> positions_x = {{"A", 0}, {"B", 1} , {"C", 2}};
map<string, int> positions_y = {{"X", 0}, {"Y", 1} , {"Z", 2}};

//          rock paper scissors
// rock     3     0      6
// paper    6     3      0
// scissors 0     6      3
int results[3][3] = {{3, 0, 6}, {6, 3, 0}, {0, 6, 3}};

int main()
{
    string x, y;
    int score = 0;   

    while (cin >> x >> y){ 
        score += points[y] + results[positions_y[y]][positions_x[x]];
    }

    cout << score << endl;
}