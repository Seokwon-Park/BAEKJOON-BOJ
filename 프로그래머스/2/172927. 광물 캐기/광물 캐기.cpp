#include <bits/stdc++.h>

using namespace std;

vector<int> g_p;
vector<string> g_m;
int cost;
int ans = INT_MAX;;
unordered_map<string, int> jmap;
unordered_map<int, int> pmap;

int get_cost(int pick, string jewel)
{
    if(pmap[pick] > jmap[jewel])
    {
        return 1;
    }
    else
    {
        //cout << jmap[jewel]/pmap[pick] << '\n';
        return jmap[jewel]/pmap[pick];
    }
}

void func(int k)
{
    for(int i = 0; i < 3; i++)
    {
        if(g_p[i] == 0) continue; // 해당 곡괭이 안남았으면 다음 곡괭이 확인
        g_p[i]--; // 그 곡괭이 하나 쓰고,
        int earn = 0;
        for(int j = 0; j< 5; j++)
        {
            earn += get_cost(i, g_m[k+j]);
            if((k+j) == g_m.size()-1)
            {
                //cout << "res " << cost+earn << '\n';
                ans = min(cost+earn, ans);
                g_p[i]++;
                return;
            }
        }
        cost += earn;
        func(k+5);
        cost -= earn;
        g_p[i]++;
    }
    if(count(g_p.begin(), g_p.end(), 0) == 3)
    {
        ans = min(cost, ans);
        return;
    }
    
    // 곡괭이 하나도 없는 경우.
}

int solution(vector<int> picks, vector<string> minerals) {
    g_p = picks;
    g_m = minerals;
    
    jmap["diamond"] = 25;
    jmap["iron"] = 5;
    jmap["stone"] = 1;
    
    pmap[0] = 25;
    pmap[1] = 5;
    pmap[2] = 1;
    
    func(0);
    
    return ans;
}