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

int x = 1;
int signal_sum = 0;
int cycle = 1;
string ctr;

void check_hz(){   

    if (cycle % 40 - 1 >= x - 1 && cycle % 40 - 1 <= x + 1)
        cout << "# ";
    else
        cout << ". ";

    if (cycle == 20 || cycle % 40 == 20 ) {
        signal_sum+= cycle * x;
    }

    if (cycle % 40 == 0)
        cout << endl;
}

int main() 
{
    int score = 0;
    string stub;
    string line;
    int value;    

    while (getline(cin, line)){
        check_hz();
        if (line[0] == 'n') {
             cycle++;
        } else {
            istringstream ss(line);
            ss >> stub >> value;
            for (int i=0; i<2; i++){
                if (i != 0) check_hz();
                cycle++;
            }
            x+=value;
        }
    }
    cout << signal_sum << endl;
}