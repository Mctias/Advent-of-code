#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool simulate(int dmg, int arm){
    int hp = 100;

    int bossHp = 100;
    int bossDmg = 8;
    int bossArm = 2;

    while(hp > 0 && bossHp > 0){
        int turnDmg = dmg - bossArm;
        if(turnDmg <= 0)
            turnDmg = 1;

        bossHp -= turnDmg;

        if(bossHp <= 0)
            break;

        int bossTurnDmg = bossDmg - arm;
        if(bossTurnDmg <= 0)
            bossTurnDmg = 1;

        hp -= bossTurnDmg;

    }

    if(bossHp <= 0){
        return true;
    }
    return false;
}

int main(){
    vector<pair<int,int>> weapons;
    vector<pair<int,int>> armors;
    vector<pair<int,int>> rings;

    weapons.push_back(make_pair(8,4));
    weapons.push_back(make_pair(10,5));
    weapons.push_back(make_pair(25,6));
    weapons.push_back(make_pair(40,7));
    weapons.push_back(make_pair(74,8));

    armors.push_back(make_pair(0,0));
    armors.push_back(make_pair(13,1));
    armors.push_back(make_pair(31,2));
    armors.push_back(make_pair(53,3));
    armors.push_back(make_pair(75,4));
    armors.push_back(make_pair(102,5));

    rings.push_back(make_pair(0,0));
    rings.push_back(make_pair(25,1));
    rings.push_back(make_pair(50,2));
    rings.push_back(make_pair(100,3));
    rings.push_back(make_pair(0,0));
    rings.push_back(make_pair(20,1));
    rings.push_back(make_pair(40,2));
    rings.push_back(make_pair(80,3));

    vector<int> winCosts;
    vector<int> lossCosts;

    for(auto w : weapons){
        for(auto a : armors ){
            for(auto r1 : rings){
                for(auto r2 : rings){
                    int dmg = w.second + r1.second + r2.second;
                    int arm = a.second;
                    int cost = w.first + a.first + r1.first + r2.first;

                    if(simulate(dmg, arm))
                        winCosts.push_back(cost);
                    else
                        lossCosts.push_back(cost);
                }
            }
        }
    }

    cout << "Minimum cost to win: " <<*min_element(winCosts.begin(), winCosts.end()) << endl;
    cout << "Maximum cost to lose: " << *max_element(lossCosts.begin(), lossCosts.end());


}