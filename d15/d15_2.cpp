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

set<pair<int, int>> beacons;
vector<pair<int, int>> sensors;
map<pair<int, int>, long long> counter;
vector<int> distances;

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

        int d = abs(x1 - x2) + abs(y1 - y2);
        distances.push_back(d);
        sensors.push_back({x1, y1});

        cords.push_back(make_pair(x1, y1));
        cords.push_back(make_pair(x2, y2));
        lines.push_back(cords);
    }

    int limit_min = 0;
    int limit_max = 4000000;

    for(int i = 0; i < lines.size(); i++){
        cout << "line  " << i << endl;
        int x1 = lines[i][0].first;
        int y1 = lines[i][0].second;    
        int x2 = lines[i][1].first;
        int y2 = lines[i][1].second;
        
        beacons.insert({x2, y2});
        int d = abs(x1 - x2) + abs(y1 - y2) + 1;
        
        int yy = 0;
        
        for(int j = -d; j <= d; j++){
            int newx = x1 + j;
            int newy1 = y1 + yy;
            int newy2 = y1 - yy;

            if (newx < limit_min || newx > limit_max) continue;
            if (newy1 < limit_min || newy1 > limit_max) continue;
            if (newy2 < limit_min || newy2 > limit_max) continue;          

            if (j < 0) yy++; else yy--;

            int rr = 0;
            for (int k=0; k<sensors.size(); k++){
                int xs = sensors[k].first;
                int ys = sensors[k].second;
                int dist_to_sensor = abs(newx - xs) + abs(newy1 - ys);
                
                if (dist_to_sensor <= distances[k]) break;
                rr++;               
            }

            if (rr == sensors.size()) counter[{newx, newy1}]++;

            rr = 0;
            for (int k=0; k<sensors.size(); k++){
                int xs = sensors[k].first;
                int ys = sensors[k].second;
                int dist_to_sensor = abs(newx - xs) + abs(newy2 - ys);
               
                if (dist_to_sensor <= distances[k]) break;
                rr++;
            }

            if (rr == sensors.size()) counter[{newx, newy2}]++;
        }
    }

    auto pr = max_element
    (
        begin(counter), end(counter),
        [] (auto p1, auto p2) {
            return p1.second < p2.second;
        }
    );

    uint64_t  resul = 1ULL * 4000000 * pr->first.first + pr->first.second;
    cout << "score: " << (uint64_t)resul << endl;  
}