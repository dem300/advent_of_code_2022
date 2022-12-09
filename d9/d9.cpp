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

const int size = 1000;
const int ini = size/2;

int visited[size][size] = {0};
vector<pair<char,int>> movements;
int h_x = ini;
int h_y = ini;
int t_x = ini;
int t_y = ini;

void move_head(char dir){

    switch (dir)
    {
        case 'R':
            ++h_x;
            break;   
        
        case 'L':
            --h_x;
            break;   
        
        case 'U':
            ++h_y;
            break;   
        
        case 'D':
            --h_y;
            break;   
    }
}

void move_tail(){

    //left or right
    if (h_y == t_y){
        if (h_x > t_x) 
            t_x++;
        else 
            t_x--;
    } else if (h_x == t_x){ //up or down
        if (h_y > t_y) 
            t_y++;
        else 
            t_y--;
    } else {
        //diagonally 
        if (h_x > t_x && h_y > t_y){ //up right
            t_x++;
            t_y++;
        } else if (h_x < t_x && h_y > t_y){ // up left
            t_x--;
            t_y++;
        } else if (h_x > t_x && h_y < t_y){ // down right
            t_x++;
            t_y--;
        } else { //down right
            t_x--;
            t_y--;
        }          
    }

    visited[t_y][t_x] = 1;
}

bool head_is_far(){   
    int x = abs(h_x - t_x);
    int y = abs(h_y - t_y);   
    if (x > 1 || y > 1 ) return true;
    return false;
}

int main() 
{
    int score = 0;
    char dir;
    int n;    

    visited[ini][ini] = 1;

    while (cin >> dir >> n ){
        movements.push_back(make_pair(dir, n));       
    }

    for(auto m:movements){
        for(int i=0; i < m.second; ++i){
            move_head(m.first);
            if (head_is_far()){
                move_tail();
            }
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            score+=visited[i][j];
        }      
    }    

    cout << score << endl;
}