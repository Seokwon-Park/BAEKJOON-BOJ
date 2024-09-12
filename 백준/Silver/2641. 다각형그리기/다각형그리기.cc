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

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int tc;
	cin >> tc;
	vector<vector<int>> ans;
	while (tc--)
	{
		vector<int> cmp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> cmp[i];
		}

		bool findAns = false;
		for (int off = 0; off < n; off++)
		{
			bool isSame = true;
			for (int i = 0; i < n; i++)
			{
				if (v[i] != cmp[(off + i) % n])
				{
					isSame = false;
					break;
				}
			}
			if (isSame)
			{
				findAns = true;
				break;
			}
		}
		if (findAns)
		{
			ans.push_back(cmp);
			continue;
		}
		//reverse
		vector<int> cmp_rev(n);
		for (int i = 0; i < n; i++)
		{
			cmp_rev[i] = (cmp[i] + 1) % 4 + 1;
		}
		reverse(cmp_rev.begin(), cmp_rev.end());

		for (int off = 0; off < n; off++)
		{
			bool isSame = true;
			for (int i = 0; i < n; i++)
			{
				if (v[i] != cmp_rev[(off + i) % n])
				{
					isSame = false;
					break;
				}
			}
			if (isSame)
			{
				findAns = true;
				break;
			}
		}
		if (findAns)
		{
			ans.push_back(cmp);
			continue;
		}
	}
	cout << ans.size() << '\n';
	for (auto vec : ans)
	{
		for (auto i : vec)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}

