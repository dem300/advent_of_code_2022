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
set<pair<int, int>> sensors;
set<pair<int, int>> beacons;
set<pair<int, int>> not_beacon;

int main() 
{
    string line;
    vector<vector<pair<int,int>>> lines;
    string str, sx, sy, stub;
    //Read input
    while (getline(cin, line)){
        vector<pair<int,int>> cords;
        istringstream ss(line);

        ss >> stub >> stub >> sx >> sy;
        int x1 = stoi(sx.substr(2, sx.size()-3));
        int y1 = stoi(sy.substr(2, sy.size()-3));
        
        ss >> stub >> stub >> stub >> stub >> sx >> sy;

        int x2 = stoi(sx.substr(2, sx.size()-3));
        int y2 = stoi(sy.substr(2, sy.size()-2));

        cords.push_back(make_pair(x1, y1));
        cords.push_back(make_pair(x2, y2));
        lines.push_back(cords);
    }

    //int y_goal = 10;
    int y_goal = 2000000;

    for(int i = 0; i < lines.size(); i++){
        int x1 = lines[i][0].first;
        int y1 = lines[i][0].second;
        int x2 = lines[i][1].first;
        int y2 = lines[i][1].second;
        
        sensors.insert({x1, y1});
        beacons.insert({x2, y2});

        int d = abs(x1 - x2) + abs(y1 - y2);
        
        for(int j = -d; j <= d; j++){
            int newx = x1 + j;
            int newy = y_goal;
            int d2 = abs(x1 - newx) + abs(y1 - newy);

            if ( d2 <= d && beacons.find({newx, newy}) == beacons.end()  
                            && sensors.find({newx, newy}) == sensors.end() 
                            && not_beacon.find({newx, newy}) == not_beacon.end()){
                    not_beacon.insert({newx, newy});
                    score++;
            }
        }
    }
    cout << "score " << score << endl;
}