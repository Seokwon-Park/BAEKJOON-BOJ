
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

	string str = "HTCKG";
	vector<int> htckg(5);
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> htckg[i];
		total += htckg[i];
	}
	int m;
	cin >> m;
	int prev = total % 10;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int htckgi;
			cin >> htckgi;
			htckg[j] -= htckgi;
		}

		int cnt = accumulate(htckg.begin(), htckg.end(), 0);
		if (cnt == 0)
		{
			cout << "07H\n";
		}
		else if (prev == 0 || prev == 1)
		{
			cout << cnt << "7H\n";
		}
		else
		{
			string res = "";
			int tmp = cnt;
			while (tmp)
			{
				res += '0' + tmp % prev;
				tmp /= prev;
			}
			reverse(res.begin(), res.end());
			cout << res << "7H\n";
		}
		prev = cnt % 10;

		if (cnt == 0)
		{
			cout << "NULL\n";
		}
		else
		{
			vector<pair<int, char>> tmp;
			for (int j = 0; j < 5; j++)
			{
				tmp.push_back({ htckg[j], str[j] });
			}
			sort(tmp.begin(), tmp.end(), [](auto a, auto b)
				{
					if (a.first == b.first)
						return a.second < b.second;
					return a.first > b.first;
				});

			for (auto [j, c] : tmp)
			{
				if (j == 0) break;
				cout << c;
			}
			cout << '\n';
		}
	}
	return 0;
}
