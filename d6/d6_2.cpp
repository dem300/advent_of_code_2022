#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <list>
#include <unordered_set>

using namespace std;

int main() 
{   
    string input;
    int score = 0;
    list<char> marker;

    cin >> input;
    for (char& c:input){
        score+=1;
        marker.push_front(c);
        if (marker.size() == 14){
            unordered_set<char> distinct(marker.begin(), marker.end());
            if (distinct.size() == 14) break;
            marker.pop_back();
        }
    }  
    cout << score << endl;
}