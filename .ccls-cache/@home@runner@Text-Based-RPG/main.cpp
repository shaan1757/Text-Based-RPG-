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
    
    int probSpAb;
    int activSpAb;
    
    int dmgincrease;

public:
  player()
  {
    level=0;
    basehealth=0;
    basedmg=0;
    activatedapability=0;
    dmgincrease=0;
  }
  string     Getname()            {return name; }
  bool       IsAlive()            {return alive;}
  int        GetLevel()           {return level;}
  int GetMnMeleeDamage() {return minMeleeDamage;}
  int GetMxMeleeDamage() {return maxMeleeDamage;}
  int        GetBaseHeal()     {return baseHeal;}
  int        GetHealth()         {return health;}
  int    GetBaseHealth()     {return baseDamage;}
  int       GetBaseDmg()     {return baseDamage;}

  virtual int Getmeleedmg()
  {
    meleedmg = minMeleeDamage + rand() % (maxMeleeDamage - minMeleeDamage);
    return meleedmg;
  }

  int restorehealth(heal)
  {
    if(health + heal > baseHealth)
       heal -= health + heal - baseHealth;
    health = health + heal;
    return heal;
  }
  virtual void takeDamage(int damage) = 0;
  virtual void useHeal(int heal) = 0;
  virtual void levelUp() = 0;
  virtual void activateSA() = 0;
  virtual void disableSA() = 0;
}; 

class hero : public player
 {
  bool criticalHitSpAb;//returns status of special ability when the turn of player
  bool shieldSpAb;//returns status of shield
  bool dealdmg;//IF applying damage
  bool rangedAttackSpAb;//if ranged damage is activated
  int dealdmg;
  int injections;
 public:
  hero(string name)
  {
    this->name="hero";//to get the player name
    alive       =true;
    upgradehealth =100;
    upgradedmg =12;
    baseheal   =500;
    injections   =2;
    activSpAb    =0;
    probabSpAb   =5;
    levelup();//leveling up
    disableSpAb();

    int GetMeleedmg()
    {
     player::Getmeleedmg();
      if(dealdmgSpAb)
        dealdmg++;
      if(criticalHitSpAb)
        return basedmg*dmgincrease;
      return meleedmg;
    }

    int GetRangeddmg()
    {
      if(dealdmgSpAb)
        dealdmg++;
      if(criticalHitSpAb)
        return basedmg*dmgincrease;
      return basedmg;
    }

    void Takedmg(int dmg)
    {
      if(shieldSpAb)
        cout<<name<<"shield neutralized the attack"<<endl;
        return;
    }
    health=health-damage;
    cout<<name<<"was hit with"<<dmg<<"damage"<<endl;
    if(health<=0(
    {
      alive=false;
      cout<<name<<"died "<<endl;
      return;
    }
    if(dealdmgSpAb)//chhecks if lifeteal ability is active and uses heal acordingly
       useHeal(dealdmg*upgradehealth/2)
  }
    void useheal(int heal)
    {
      if(health==basehealth)
      {
        cout<<name<<"s health is max cant exceed that"<<endl;
        return;
      }
      heal= restorehealth(heal);
      cout<<name<<"s health increased by"<<heal<<"HP"<<endl;
    }
    int useInjections()//using injections to increase health with conditions
    {
      if(injection==0)
        return false;

      injection--;
      return true;
    }
    void activateSpAb()
    {
      if(activSpAb==0)//player has no speciak ability
        return;
      if(rangedAttackSpAb)
        rangedAttackSpAb=false;
        return;
    }
    disabkeSpAb();
    if(rand()%probabSpAb!=0)//probability  to activate apecial ability
      return;

    int ChoiceSpAb = rand()%activatedSpAb;
 };


int main() {
 
}