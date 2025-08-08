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

int l, n;
string v[25];
vector<string> ans;
bool isUsed[25];


void func(int k)
{
	if (k == l)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << '\n';
		}
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		if (isUsed[i]) continue;
		if (ans.empty())
		{
			isUsed[i] = true;
			ans.push_back(v[i]);
			func(k + 1);
			ans.pop_back();
			isUsed[i] = false;
		}
		else
		{
			bool chk = true;
			for (int j = 0; j < k; j++)
			{
				if (v[i][j] != ans[j][k])
				{
					chk = false;
					break;
				}
			}
			if (chk)
			{
				isUsed[i] = true;
				ans.push_back(v[i]);
				func(k + 1);
				ans.pop_back();
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v, v+n);

	func(0);

	cout << "NONE";

	return 0;
}