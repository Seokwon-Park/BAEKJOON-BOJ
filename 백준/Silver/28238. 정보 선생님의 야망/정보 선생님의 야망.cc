#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool v[1000005][5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<bool> c = { 0,0,0,1,1 };

	int ans = 0;
	vector<bool> ansv;

	do
	{
		vector<int> day;
		for (int i = 0; i < 5; i++)
		{
			if (c[i])
			{
				day.push_back(i);
			}
		}

		int x = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i][day[0]] && v[i][day[1]])
			{
				x++;
			}
		}
		if (ans < x)
		{
			ans = x;
			vector<bool> temp(5, 0);
			temp[day[0]] = true;
			temp[day[1]] = true;
			ansv = temp;
		}
	} while (next_permutation(c.begin(), c.end()));

	cout << ans << '\n';
	if (ans != 0)
	{
		for (auto i : ansv)
		{
			cout << i << ' ';
		}
	}
	else
	{
		cout << "1 1 0 0 0";
	}


	return 0;
}