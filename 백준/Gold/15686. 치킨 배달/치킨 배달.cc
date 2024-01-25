
#include <bits/stdc++.h>

using namespace std;

int board[55][55];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> cks, hs;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				hs.push_back({ j, i });
			}
			if (board[i][j] == 2)
			{
				cks.push_back({ j,i });
			}
		}
	vector<int> comb(cks.size(), 0);
	fill(comb.end() - m, comb.end(), 1);

	int answer = INT_MAX;
	do
	{
		int total = 0;
		for (int j = 0; j < hs.size(); j++)
		{
			auto [hx, hy] = hs[j];
			int mn = INT_MAX;
			for (int i = 0; i < comb.size(); i++)
			{
				if (comb[i] == 1)
				{
					auto [cx, cy] = cks[i];
					int dist = abs(cx - hx) + abs(cy - hy);
					mn = min(mn, dist);
				}
			}
			total += mn;
		}
		answer = min(total, answer);
	} while (next_permutation(comb.begin(), comb.end()));

	cout << answer;

	return 0;
}
