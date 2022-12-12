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

struct monkey {
    vector<unsigned long int> items;
    string op;
    string op_val;
    int div;
    int throw_true;
    int throw_false;
};

vector<monkey> monkeys = {{{57}, "*", "13", 11, 3 , 2}, 
                         {{58, 93, 88, 81, 72, 73, 65}, "+", "2", 7, 6, 7},
                         {{65, 95}, "+", "6", 13, 3, 5},
                         {{58, 80, 81, 83}, "*", "old", 5, 4 , 5},
                         {{58, 89, 90, 96, 55}, "+", "3", 3, 1 , 7},
                         {{66, 73, 87, 58, 62, 67}, "*", "7", 17, 4 , 1},
                         {{85, 55, 89}, "+", "4", 2, 2 , 0},
                         {{73, 80, 54, 94, 90, 52, 69, 58}, "+", "7", 19, 6 , 0},
                         };

int main() 
{
    unsigned long int  score = 0;
    map<int, int> n_times;
    vector<int> count {0, 0, 0, 0, 0, 0, 0, 0};

    int lcm = 1;
    for (auto m: monkeys){
        lcm*=m.div;
    }

    for (int i=0; i<10000;++i){
        for (int j=0; j<monkeys.size();++j){
            auto m = monkeys[j];
            for (auto item: m.items){
                int val;
                unsigned long int worry = 0;
                if (m.op_val == "old") val = item;
                else val = stoi(m.op_val);

                if (m.op == "+") worry = item + val;
                if (m.op == "*") worry = item * val;               

                //worry = floor(worry/3);
                worry = worry % lcm;

                if (worry % m.div == 0) monkeys[m.throw_true].items.push_back(worry);
                else monkeys[m.throw_false].items.push_back(worry);
         
                count[j]++;
            }
            monkeys[j].items.clear();
        }
    }

    sort(count.begin(), count.end());    

    unsigned long int t1 = count.back();
    count.pop_back();
    unsigned long int t2 = count.back();
    score = t1 * t2;
    
    cout << score << endl;
}