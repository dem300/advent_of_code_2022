#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int score = 0;
int dx[2] = {-1,1};
int dy[2] = {1,1};
int n = 0, m = 0;

int drop(int x, int y, vector<vector<char>> &grid){

    if (x < 0 || x > n || y < 0 || y +1 > m) return -1;

    if (grid[y][x] == 'o') return -1;

    //down
    if (grid[y + 1][x] == '.') return drop(x, y + 1, grid);
    
    //left
    if (grid[y + dy[0]][x + dx[0]] == '.') return drop(x - 1, y, grid);

    //right
    if (grid[y + dy[1]][x + dx[1]] == '.') return drop(x + 1, y, grid);   
    
    grid[y][x] = 'o';
    score++;

    return 0;
}

void print_grid(vector<vector<char>> &grid){
    cout << endl;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 480; j < 520; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() 
{
    string line;
    vector<vector<pair<int,int>>> lines;
    pair<int, int> end;
    string str;    

    while (getline(cin, line)){   
        istringstream ss(line);
        vector<pair<int,int>> cords;
        while (ss >> str){        
            if (str == "->") continue;
            int pos = str.find(",");
            int x = stoi(str.substr (0, pos));
            int y = stoi(str.substr (pos + 1));
            cords.push_back(make_pair(x, y));
            n = max(n, x);
            m = max(m, y);
        }
        lines.push_back(cords);
    }

    //part2
    m = m + 2;
    n = n + n;

    vector<vector<char>> grid(m +1, vector<char>(n+1,'.'));

    for(int i = 0; i < lines.size(); i++){
        for(int j = 0; j < lines[i].size()-1 ; j++){
            int x1 = lines[i][j].first;
            int y1 = lines[i][j].second;
            int x2 = lines[i][j + 1].first;
            int y2 = lines[i][j + 1].second;

            if (x1 == x2){
                for(int k = min(y1, y2); k <= max(y1, y2); k++){
                    grid[k][x1] = '#';
                }
            } else {
                for(int k = min(x1, x2); k <= max(x1, x2); k++){
                    grid[y1][k] = '#';
                }
            }
        }
    }   
   
    //floor p2
    for(int j = 0; j < grid[0].size() ; j++){
         grid[m][j] = '#';
    }  

 
    while (drop(500, 0, grid) != -1){
        print_grid(grid);
    }

    cout << "score" << score << endl;
}