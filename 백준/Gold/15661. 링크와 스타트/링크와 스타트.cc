#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[20][20];
int isused[20];
int n;
vector<int> start;
vector<int> link;

int ans = INT_MAX;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; i++)
	{
		cin >> b[i / n][i % n];
	}

	for (int i = 1; i < n; i++)
	{
		vector<int> pick(n, 0);
		fill(pick.end() - i, pick.end(), 1);
		do
		{
			vector<int> start;
			vector<int> link;
			for (int i = 0; i < n; i++)
			{
				if (pick[i])
					start.push_back(i);
				else
					link.push_back(i);
			}

			int s = 0;
			int l = 0;
			for (int i = 0; i < start.size(); i++)
			{
				for (int j = 0; j < start.size(); j++)
				{
					s += b[start[i]][start[j]];
				}
			}

			for (int i = 0; i < link.size(); i++)
			{
				for (int j = 0; j < link.size(); j++)
				{
					l += b[link[i]][link[j]];
				}
			}

			ans = min(ans, abs(s - l));
		} while (next_permutation(pick.begin(), pick.end()));
	}
	
	cout << ans;

	return 0;
}