#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll w[4][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t, k;
	cin >> t >> k;

	int r, c;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> w[i][j];
			if (w[i][j] == -1)
			{
				r = i;
				c = j;
			}
		}
	}

	ll st = 0;
	ll en = LLONG_MAX / 2;

	while (st < en)
	{
		ll mid = (st + en) / 2;

		w[r][c] = mid;

		vector<ll> winPoint(4, 0);
		vector<ll> totalGoal(4, 0);
		vector<ll> goalGap(4, 0);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j) continue;
				ll ipt = w[i][j];
				ll jpt = w[j][i];
				totalGoal[i] += ipt;
				goalGap[i] += ipt - jpt;
				if (ipt > jpt)
					winPoint[i] += 3;
				else if (ipt == jpt)
					winPoint[i] += 1;
			}
		}

		vector<int> team = { 0,1,2,3 };
		sort(team.begin(), team.end(), [=](int a, int b)
			{
				if (winPoint[a] == winPoint[b])
				{
					if (goalGap[a] == goalGap[b])
					{
						if (totalGoal[a] == totalGoal[b])
						{
							return a < b;
						}
						return totalGoal[a] > totalGoal[b];
					}
					return goalGap[a] > goalGap[b];
				}
				return winPoint[a] > winPoint[b];
			}
		);

		int ix = find(team.begin(), team.end(), r) - team.begin();
		if (ix > 1) // 진출 못하는 경우
		{
			st = mid + 1;
		}
		else
		{
			en = mid;
		}
	}
	if (st > k)
		cout << -1;
	else
		cout << st;



	return 0;
}
