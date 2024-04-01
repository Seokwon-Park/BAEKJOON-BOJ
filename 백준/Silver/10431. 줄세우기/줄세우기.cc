#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 1; i<=n;i++)
	{
		int tc;
		cin >> tc; // =i;
		vector<int> v(20);
		for (auto& i : v)
			cin >> i;
		vector<int> simul;
		int ans = 0;
		for (auto i : v)
		{
			if (simul.empty())
			{
				simul.push_back(i);
				continue;
			}
			
			int insertpos = -1;
			int swapped = 0;
			for (int j = simul.size() - 1; j >= 0; j--)
			{
				if (i < simul[j])
				{
					insertpos = j;
					swapped++;
				}
				else
				{
					break;
				}
			}
			if (insertpos == -1)
				simul.push_back(i);
			else
			{
				simul.insert(simul.begin()+insertpos, i);
				ans += swapped;
			}
		}
		cout << i << ' ' << ans << '\n';

	}


	return 0;
}