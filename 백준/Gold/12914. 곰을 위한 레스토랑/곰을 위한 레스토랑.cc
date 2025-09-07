#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (ans.empty())
		{
			cout << x << ' ';
			ans.push_back(x);
		}
		else
		{
			int ix = lower_bound(ans.begin(), ans.end(), x) - ans.begin();
			int val = x;
			if (ix == ans.size())
			{
				if (ans.back() + d <= val)
				{
					ans.push_back(val);
				}
				else
				{
					val = ans.back() + d;
					ans.push_back(val);
				}
				cout << val << ' ';
			}
			else
			{
				int i = ix;
				for (i = ix; i < ans.size(); i++)
				{
					if (i == 0)
					{
						if (val <= ans[i] - d)
						{
							break;
						}
						else
						{
							val = ans[i] + d;
						}
					}
					else
					{
						if (val < ans[i - 1] + d)
						{
							val = ans[i - 1] + d;
						}
						if (val <= ans[i] - d)
						{
							break;
						}
						else
						{
							val = ans[i] + d;
						}
					}
				}
				cout << val << ' ';
				ans.insert(ans.begin() + i, val);
			}
		}
	}

	return 0;
}