#include <bits/stdc++.h>
#include <random>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    
    int resp;
    
    vector<int> avec;
    vector<int> bvec;
    for (int i = 1; i <= 10000; i++)
    {
        avec.push_back(i);
        bvec.push_back(i);
    }

    random_device rd;

    shuffle(avec.begin(), avec.end(), rd);
    shuffle(bvec.begin(), bvec.end(), rd);

    while (!avec.empty())
    {
        int a = avec.back();
        avec.pop_back();

        cout << "? A " << a << endl;
        cin >> resp;
        if (resp == 1) 
        {
            while (!bvec.empty())
            {
                int b = bvec.back();
                bvec.pop_back();
                cout << "? B " << b << endl;
                cin >> resp;
                if (resp == 1)
                {
                    std::cout << "! " << a + b;
                    return 0;
                }
            }
        }
        //else continue;
    }

	return 0;
}