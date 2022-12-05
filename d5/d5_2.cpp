#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

struct move_s{
    int n;
    int from;
    int to;

};

int main() 
{
    std::ifstream input("input.txt");
    string line;
    int n, from, to;
    map<int, stack<string>> crates;
    int score = 0;
    vector<move_s> moves;
    
    while(getline(input, line)){
        int pos = line.find("[");
        if (pos != std::string::npos) {
            do {
                int stack_num = (pos / 4) + 1;
                cout << stack_num << endl;
                crates[stack_num].push(line.substr(pos+1, 1));
                pos = line.find("[", pos+1);
            } while (pos != std::string::npos);
        } else if (line.find("move") != std::string::npos){
            int pos_from = line.find("from");
            int pos_to = line.find("to");
            int pos_blank = line.find(" ");
            int tam = pos_to  - pos_from - 5- 1;
           
            n = stoi(line.substr(pos_blank + 1, pos_from - pos_blank  -2));
            from = stoi(line.substr(pos_from + 5, tam));
            to = stoi(line.substr(pos_to + 3));

            move_s m = {n, from, to};
            moves.push_back(m);
        }        
    }

    for (int i = 0; i < crates.size(); i++){
        stack<string> result;
        while(!crates[i+1].empty()) { 
            result.push(crates[i+1].top());
            crates[i+1].pop();
        }
        crates[i+1] = result;
    }

    for (auto &m: moves){
        cout << m.n << endl;
        cout << m.from << "->" << m.to << endl;
        stack<string> crates_picked;
 
        for (int i = 0; i < m.n; i++){
            crates_picked.push(crates[m.from].top());
            crates[m.from].pop();
        }

        while(!crates_picked.empty()){
            crates[m.to].push(crates_picked.top());
            crates_picked.pop();
        }        
    }

    string top;
    for (int i = 0; i < crates.size(); i++){
        top += crates[i+1].top();
    }    
    cout << top << endl;
}