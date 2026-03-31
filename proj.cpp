#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct player{
    string user;
    string rank;
    string lvl;
    string role;
    string agent;
};

player perm[10]{};
player temp;


string inputrank, inputranklvl, line, tempplayerrank, tempplayeruser, tempplayerranklvl;
string permplayers[20], permplayersrank[20], permplayersranklvl[20];
int location;

int main(){
    ifstream inFile("finaldata.csv");
    if (inFile.fail()) {
        cout << "wompwomp, failed to open" << endl;
        return 0; //exit code
    }

    cout << "give rank and rank lvl seperated by space, no immortal or radiant" << endl;
    // have to add checker that they put in something acceptable
    cin >> inputrank;
    cin >> inputranklvl;
    int i;
    
    while(getline(inFile, line) && i < 10){
        //getting first username
        location = line.find(',');
        temp.user = line.substr(0,location);
        line = line.substr(location+1, line.length());
        //skipping numbers
        location = line.find(',');
        line = line.substr(location+1, line.length());
        //gettings ranks
        location = line.find(',');
        temp.rank = line.substr(0,location);
        line = line.substr(location+1, line.length());
        //getting ranklvl
        location = line.find(',');
        temp.lvl = line.substr(0,location);
        line = line.substr(location+1, line.length());
        //getting player role
        location = line.find(',');
        temp.role = line.substr(0,location);
        line = line.substr(location+1, line.length());
        //getting player agent
        location = line.find(',');
        temp.agent = line.substr(0,location);

        //checking if rank of player matches given rank, if yes, saves all of player's info
        if (temp.rank == inputrank && temp.lvl == inputranklvl){
            perm[i].user = temp.user;
            perm[i].rank = temp.rank;
            perm[i].lvl = temp.lvl;
            perm[i].role = temp.role;
            perm[i].agent = temp.agent;
            i++;
        }
    }
    cout << endl;
    cout << "here team 1" << endl;
    for(int j = 0; j<5; j++){
        cout << perm[j].user <<" "<< perm[j].rank <<" "<< perm[j].lvl << endl;
    }
    cout << endl;
    cout << "here team 2" << endl;
    for(int j = 5; j<10; j++){
        cout << perm[j].user <<" "<< perm[j].rank <<" "<< perm[j].lvl << endl;
    }
    //test
}

