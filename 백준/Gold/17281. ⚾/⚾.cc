#include <bits/stdc++.h>

using namespace std;

bool base[4];
int score;
int start;
int out;


void simul(int run)
{
	if (run == 0)
	{
		out++;
		return;
	}
	base[0] = true;
	for (int i = 3; i >= 0; i--)
	{
		if (base[i])
		{
			if (i + run >= 4)
			{
				score++;
			}
			else
			{
				base[i + run] = true;
			}
			base[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<vector<int>> pl;
	for (int i = 0; i < n; i++)
	{
		vector<int> scores(9);
		for (int i = 0; i < 9; i++)
		{
			cin >> scores[i];
		}
		pl.push_back(scores);
	}
	
	vector<int> order(9);
	for (int i = 0; i < 9; i++)
	{
		order[i] = i;
	}

	int ans = INT_MIN;
	do
	{
		if (order[3] != 0) continue;
		score = 0; 
		start = 0; // 1번 타자부터 시작
		for (int i = 0; i < n; i++)
		{
			out = 0;
			fill(base, base + 4, false);
			for (int j = start; out != 3; j = (j+1)%9)
			{
				simul(pl[i][order[j]]);
				start = (j+1)%9;
			}
		}
		ans = max(ans, score);
	} while (next_permutation(order.begin(), order.end()));

	cout << ans;

	return 0;
}
