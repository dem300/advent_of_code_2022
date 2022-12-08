#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <list>
#include <sstream>

using namespace std;

vector<vector<int>> matrix;
int max_x, max_y;


int visible(int x, int y){   

    //Border
    if (x == 0 || y == 0 || x == max_x - 1 || y == max_y - 1) return 1;

    vector<int> newVec(matrix[y].begin(), matrix[y].begin() + x);
    vector<int> newVec2(matrix[y].begin() + x + 1, matrix[y].end());
   
    //Horizontal
    auto max_left = max_element(matrix[y].begin(), matrix[y].begin() + x);
    auto max_right = max_element(matrix[y].begin() + x + 1, matrix[y].end());
    if (matrix[y][x] > *max_left || matrix[y][x] > *max_right) return 1;

    //Vertical
    vector<int> vertical;
    for (int i = 0; i < max_y; i++){
        vertical.push_back(matrix[i][x]);     
    }
  
    max_left = max_element(vertical.begin(), vertical.begin() + y );
    max_right = max_element(vertical.begin() + y + 1, vertical.end());
    if (matrix[y][x] > *max_left || matrix[y][x] > *max_right) return 1;

    return 0;

}

int main() 
{   
    string line;
    int score = 0;    

    while (cin >> line){
        vector<int> tmp;
        for (auto &c: line){
            int a = c - 48;
            tmp.push_back(a);            
        }
        max_x = tmp.size();
        matrix.push_back(tmp);
    }

    max_y = matrix.size();

    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix[i].size(); j++){
            score += visible(j, i);         
        }
    }

    cout << score << endl;
}