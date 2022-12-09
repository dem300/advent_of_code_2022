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

struct point{    
    int x;
    int y; 
};

const int size = 1000;
const int ini = size/2;

int visited[size][size] = {0};
vector<pair<char,int>> movements;
vector<point> points; 


void move_head(char dir){

    switch (dir)
    {
        case 'R':
            ++(points[0].x);
            break;   
        
        case 'L':
            --(points[0].x);
            break;   
        
        case 'U':
            ++(points[0].y);
            break;   
        
        case 'D':
            --(points[0].y);
            break;   
    } 
}

void move_point(int i){

    int h_y = points[i-1].y;
    int h_x = points[i-1].x;

    int t_y = points[i].y;
    int t_x = points[i].x;

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

    points[i].y = t_y;
    points[i].x = t_x;    

    if (i == 9)
        visited[t_y][t_x] = 1;

}

bool next_is_far(int i){    
    int x = abs(points[i-1].x - points[i].x);
    int y = abs(points[i-1].y - points[i].y);        
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

    //Init points
    for (int i = 0; i < 10; i++){
        point p = {ini, ini};
        points.push_back(p);
    }

    for(auto m:movements){      
        for(int i=0; i < m.second; ++i){
            move_head(m.first);
            for (int i = 1; i < 10; i++){
                if (next_is_far(i)){
                    move_point(i);
                }
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