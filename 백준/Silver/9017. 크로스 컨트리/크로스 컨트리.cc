#include <bits/stdc++.h>

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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		map<int, int> teamNum;
		vector<int> order;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			teamNum[k]++;
			order.push_back(k);
		}

		map<int, int> teamScore;
		map<int, vector<int>> teamOrder;
		int score = 1;
		for (int i = 0; i < n; i++)
		{
			int tmp = order[i];
			if (teamNum[order[i]] >= 6)
			{
				teamOrder[order[i]].push_back(score);
				if (teamOrder[order[i]].size() <= 4)
				{
					teamScore[order[i]] += score;
				}
				score++;
			}
		}

		int mnScore = INF;
		int mnTeam = 0;
		vector<int> teams;
		for (auto [ix, score] : teamScore)
		{
			if (score < mnScore)
			{
				mnScore = score;
				mnTeam = ix;
				teams.clear();
				teams.push_back(ix);
			}
			else if (score == mnScore)
			{
				teams.push_back(ix);
			}
		}

		if (teams.size() == 1)
			cout << teams[0];
		else
		{
			int mnFifth = INF;
			int mnIx = 0;
			for (int i = 0; i < teams.size(); i++)
			{
				if (teamOrder[teams[i]][4] < mnFifth)
				{
					mnFifth = teamOrder[teams[i]][4];
					mnIx = teams[i];
				}
			}
			cout << mnIx;
		}

		cout << '\n';
	}

	return 0;
}