#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string w;
		int k;
		cin >> w >> k;

		vector<vector<int>> index(26);
		vector<int> maxLen(26, 0);
		vector<int> minLen(26, INF);
		for (int i = 0; i < w.size(); i++)
		{
			int ch = w[i] - 'a';
			index[ch].push_back(i);
		}
		
		int mn = INF;
		int mx = 0;
		for (int i = 0; i < 26; i++)
		{
			if (index[i].size() < k)continue;
			for (int j = 0; j < index[i].size() - k + 1; j++)
			{
				int sz = index[i][j + k - 1] - index[i][j]+1;
				mn = min(mn, sz);
				mx = max(mx, sz);
			}
		}
		if (mn == INF)
			cout << -1 << '\n';
		else
			cout << mn << ' ' << mx << '\n';
	}


	return 0;
}

