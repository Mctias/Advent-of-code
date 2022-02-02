#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

// Please don't look at this code :(

using namespace std;
int optimalCost = INT_MAX; 

void simulate(int hp, int mana, int arm, int armTimer, int dotsTimer, int manaTimer, int bossHp, int bossDmg, int totalCost){
    if(totalCost > optimalCost)
        return;
    if(mana < 53)
        return;
    //cout << "---Player Turn---" << endl;
    //cout << "-Player has " << hp << " hit points, " << arm << " armor and " << mana << " mana." <<endl; 

    --hp;
    if(hp <= 0)
        return;
    
    // Effects

    if(armTimer > 0){
        arm = 7;
        armTimer -= 1;
        //cout << "Shield is active. The timer is now " << armTimer << endl;
    }
    else{
        arm = 0;
    }
    if(dotsTimer > 0){
        bossHp -= 3;
        dotsTimer -= 1;
        //cout << "Poison deals 3 damage; its timer is now " << dotsTimer;

        if(bossHp <= 0){
            optimalCost = totalCost;
            return;
        }
    }
    if(manaTimer > 0){
        mana += 101;
        manaTimer -= 1;
        //cout << "Recharge is active. Player gains 101 mana. The timer is now " << manaTimer << endl;
    }


    // Player turn
    // Cast spell
    int spell = rand() % 5;

    if(spell == 4 && manaTimer != 0)
        spell = rand() % 4;
    if(spell == 3 && dotsTimer != 0)
        spell = rand() % 3;
    if(spell == 2 && manaTimer != 0)
        spell = rand() % 2;
    

    if(mana >= 53){
        if(spell == 0){
            mana -= 53;
            totalCost += 53;
            bossHp -= 4;
            //cout << "The player casts Magic missiles and deals 4 damage! The boss has " << bossHp << " hit points left." << endl;
        }
        if(spell == 1 && mana >= 73){
            mana -= 73;
            totalCost += 73;
            bossHp -= 2;
            hp += 2;
            //cout << "The player casts Drain and deals 2 damage while healing for 2! The boss has " << bossHp << " hit points left." << endl;
        }
        if(spell == 2 && mana >= 113){
            mana -= 113;
            totalCost += 113;
            armTimer = 6;
            //cout << "The player casts Shield!" << endl;
        }
        if(spell == 3 && mana >= 173){
            mana -= 173;
            totalCost += 173;
            dotsTimer = 6;
           //cout << "The player casts Poison!" << endl;
        }
        if(spell == 4 && mana >= 229){
            mana -= 229;
            totalCost += 229;
            manaTimer = 5;
            //cout << "The player casts Recharge!" << endl;
        }

        if(bossHp <= 0){
            optimalCost = totalCost;
            //cout << "Player won and spent: " << totalCost << " mana!";
            return;
        }
    }
    else{
        return;
    }
    

    //Boss turn
    //cout << "---Boss Turn---" << endl;
    //cout << "-Boss has " << bossHp << " hit points." << endl;

    // Effects

    if(armTimer > 0){
        arm = 7;
        armTimer -= 1;
        //cout << "Shield is active. The timer is now " << armTimer << endl;
    }
    else {
        arm = 0;
    }
    if(dotsTimer > 0){
        bossHp -= 3;
        dotsTimer -= 1;
        //cout << "Poison deals 3 damage; its timer is now " << dotsTimer << endl;

        if(bossHp <= 0){
            optimalCost = totalCost;
            return;
        }
    }
    if(manaTimer > 0){
        mana += 101;
        manaTimer -= 1;
        //cout << "Recharge is active. Player gains 101 mana. The timer is now " << manaTimer << endl;
    }

    if(arm >= bossDmg)
        hp -= 1;
    else
        hp -= (bossDmg - arm);
   //cout << "The boss hits the player and deals damage! The player has " << hp << " hit points left." << endl;

    if(hp <= 0){
        //cout << "The boss won... :(";
        return;
    }

    simulate(hp, mana, arm, armTimer, dotsTimer, manaTimer, bossHp, bossDmg, totalCost);

}

int main(){
    srand((unsigned) time(0));
    
    int hp = 50;
    int mana = 500;
    int arm = 0; 

    int bossHp = 55;
    int bossDmg = 8;


    while(optimalCost >= 1295)
        simulate(hp, mana, arm, 0, 0, 0, bossHp, bossDmg, 0);
    

    cout << optimalCost;


}