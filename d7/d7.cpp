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

const int FILESYSTEM = 70000000;
const int NEEDED_UPDATE = 30000000;

int part1 = 0;
vector<pair<int,string>> dir_space;

struct file{
    string name;
    int size = 0;
    bool isDir = false;
    vector<file> files;
    file* parent;
};

int size_dir(const file& input){    
    int result = input.size;
    for (auto &f: input.files){      
        result+=size_dir(f);
    }

    //Part1
    if (input.isDir && result <= 100000){
        part1+=result;
        cout << "part1" << "=" << part1 << endl;
    }

    if (input.isDir) {
        //cout << input.name << "=" << result << endl;
        dir_space.push_back(make_pair(result, input.name));
    }
    
    return result;
}

int main() 
{   
    string line;
    int score = 0; 
    file *p_pwd, *p_root;
   
    file root;
    root.name = "/";
    root.isDir = true;
    root.parent = nullptr;

    p_pwd = &root;
    p_root = &root;

    while (getline(cin, line)){
        if (line[0] == '$') {
            string command, dir, stub;
            istringstream ss(line);
            ss >> stub >> command;
            if (command == "cd"){
                ss >> dir;
                if (dir == ".."){
                    p_pwd = p_pwd->parent;
                } else if (dir == "/"){
                    p_pwd = &root;
                } else {
                    for (auto &v: p_pwd->files){
                        if (v.name == dir){
                            p_pwd = &v;
                            break;
                        }
                    }
                }
            }
        } else {
            istringstream ss(line);
            string part1, part2;
            ss >> part1 >> part2;
            file newFile;
            newFile.name = part2;
            if (isdigit(part1[0])){
                newFile.size = stoi(part1);
            } else {
                newFile.isDir = true;
            }
            newFile.parent = p_pwd;
            (p_pwd->files).push_back(newFile);
        }
    }
    
    size_dir(root);

    //PART2
    sort(dir_space.begin(), dir_space.end());

    int space_used = dir_space.back().first;
    int space_unused = FILESYSTEM - space_used;
    int space_need_free = 30000000 - space_unused; 

    for (auto d: dir_space){
        if (d.first >= space_need_free){
            cout << "part2" << endl;
            cout << d.second << "=" << d.first << endl;
            break;
        }
    }
}