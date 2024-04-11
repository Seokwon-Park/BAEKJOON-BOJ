#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[11][11];
int n;
int ans = INT_MAX;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
		}
	}
	
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	do
	{
		vector<int> tmp = v;
		tmp.push_back(tmp[0]);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (b[tmp[i]][tmp[i + 1]] == 0)
			{
				res = 0;
				break;
			}
			res += b[tmp[i]][tmp[i + 1]];
		}
		if(res != 0)
			ans = min(ans, res);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;

	return 0;
}
