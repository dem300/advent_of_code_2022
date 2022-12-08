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

int max_view(int x, int y){

    int left = 0, right = 0, up = 0, down = 0;   

    //Border
    if (x == 0 || y == 0 || x == max_x - 1 || y == max_y - 1) return 0;

    vector<int> v_left(matrix[y].begin(), matrix[y].begin() + x);  
    vector<int> v_right(matrix[y].begin() + x + 1, matrix[y].end());   

    for (auto it = v_left.rbegin(); it != v_left.rend(); ++it){
        left++;
        if (matrix[y][x] <= *it) break;
    }  

    for (auto it = v_right.begin(); it != v_right.end(); ++it){      
        right++;
        if (matrix[y][x] <= *it) break;
    }

    //Vertical
    vector<int> vertical;
    for (int i = 0; i < max_y; i++){
        vertical.push_back(matrix[i][x]);       
    }

    vector<int> v_up(vertical.begin(), vertical.begin() + y);  
    vector<int> v_down(vertical.begin() + y + 1, vertical.end());

    for (auto it = v_up.rbegin(); it != v_up.rend(); ++it){
        up++;
        if (matrix[y][x] <= *it) break;
    }   

    for (auto it = v_down.begin(); it != v_down.end(); ++it){
        down++;
        if (matrix[y][x] <= *it) break;
    }

    return left * right * up * down;

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
            score = max(max_view(j, i), score);
        }
    }

    cout << score << endl;
}