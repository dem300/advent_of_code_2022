#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

map<string, int> positions_x = {{"A", 0}, {"B", 1} , {"C", 2}};
map<string, int> positions_y = {{"X", 0}, {"Y", 1} , {"Z", 2}};

//          rock paper scissors
// rock     3     0      6
// paper    6     3      0
// scissors 0     6      3
int results[3][3] = {{3, 0, 6}, {6, 3, 0}, {0, 6, 3}};

map<string, int> points_action = {{"X", 0}, {"Y", 3} , {"Z", 6}};

int get_points_element(string x, string y){
    for (int i= 0;i < 3; i++){
        if (results[i][positions_x[x]] == points_action[y])
            return i + 1;
    }

    return -99;
}

int main()
{
    string x, y;
    int score = 0;   

    while (cin >> x >> y){      
        score += get_points_element(x, y) + points_action[y];
    }

    cout << score << endl;
}