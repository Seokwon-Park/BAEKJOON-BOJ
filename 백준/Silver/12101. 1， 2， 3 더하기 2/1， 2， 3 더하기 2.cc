#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<string> dptmp[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dptmp[1].push_back("1");
	dptmp[2].push_back("1+1");
	dptmp[2].push_back("2");
	dptmp[3].push_back("1+1+1");
	dptmp[3].push_back("1+2");
	dptmp[3].push_back("2+1");
	dptmp[3].push_back("3");
	for (int i = 4; i < 11; i++)
	{
		for (int j = 0; j < dptmp[i - 1].size(); j++)
		{
			dptmp[i].push_back(dptmp[i - 1][j] + "+1");
		}
		for (int j = 0; j < dptmp[i - 2].size(); j++)
		{
			dptmp[i].push_back(dptmp[i - 2][j] + "+2");
		}
		for (int j = 0; j < dptmp[i - 3].size(); j++)
		{
			dptmp[i].push_back(dptmp[i - 3][j] + "+3");
		}
	}

	int n, k;
	cin >> n >> k;
	if (dptmp[n].size() < k)
	{
		cout << -1;
		return 0;
	}
	sort(dptmp[n].begin(), dptmp[n].end());
	cout << dptmp[n][k - 1];

	return 0;
}