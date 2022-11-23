#include <iostream>
using namespace std;

class Player
{
proteted:
string name;//store player name
bool alive;//cheeck if the player is alive
int level;//integer indicate to the level the player is in

int health;
int heal;

int basehealth;
int upgradehealth;
int baseheal;

int basedmg;
int upgradedmg;

int meleedmg;
int minmeleedmg;
int maxmeleedmg;

int rangeddmg;
int minrangeddmg;
int maxrangeddmg;

int defence;

int  specialabilities;



void Displaymsg()//function to print the story
{
  cout<<"The Story ";
}
};

class level1  : public Player
{

}; 


int main() {
 
}