#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    auto itr = attacks.end()-1;    
    int time = (*itr)[0];
    
    int curHealth = health;
    int cntHeal = 0;
    auto atk_ix = attacks.begin();
        
    for(int i =1; i<= time; i++)
    {
        vector<int> attack = *atk_ix;
        if(attack[0] == i)
        {
            curHealth -= attack[1];
            cntHeal = 0;
            atk_ix++;
            if(curHealth <= 0)
                return -1;
            continue;
        }
        curHealth+= bandage[1];
        cntHeal++;
        if(cntHeal == bandage[0])
        {
            curHealth += bandage[2];
            cntHeal =0;
        }
        if(curHealth >= health)
        {
            curHealth = health;
            continue; 
        }
    }
    
    return curHealth;
}