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

bool isPossible(int row, int col, int n, int m){
  return !(row >= n || col >= m || row < 0 || col < 0);
}

int main() 
{
    string line;
    vector<string> grid;
    pair<int, int> end;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    while (cin >> line){
        grid.push_back(line);
    }

    int n = grid.size();
    int m = grid[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'E') {
                end = make_pair(i,j);
                grid[i][j] = 'z';
            }
        }
    }

    ////////////////////

    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    visited[end.first][end.second] = true;

    q.push(make_pair(0, end));
    while(!q.empty()){
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        
        if(grid[row][col] == 'a'){
            cout << dist << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            if(isPossible(row + dx[i], col + dy[i], n, m) && !visited[row + dx[i]][col + dy[i]]){
                char prev = grid[row + dx[i]][col + dy[i]] == 'S' ? 'a' : grid[row + dx[i]][col + dy[i]];
                if(grid[row][col] - prev <=1){
                    visited[row + dx[i]][col + dy[i]] = true;
                    q.push(make_pair(dist + 1, make_pair(row + dx[i], col + dy[i])));
                }
            }
        }
    }
    cout << "failed" << endl;
}