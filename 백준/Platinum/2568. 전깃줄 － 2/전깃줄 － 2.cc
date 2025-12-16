#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	vector<pii> lis;
	vector<int> ix(n);

	for (int i = 0; i < n; i++)
	{
		if (lis.empty() || lis.back().second < v[i].second)
		{
			lis.push_back(v[i]);
			ix[i] = lis.size() - 1;
		}
		else 
		{
			int lb = lower_bound(lis.begin(), lis.end(), v[i], [](const auto& a, const auto& b)
				{
					return a.second < b.second;
				}) - lis.begin();
			lis[lb] = v[i];
			ix[i] = lb;
		}
	}

	int j = lis.size() - 1;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--)
	{
		if (ix[i] == j)
		{
			j--;
		}
		else
		{
			ans.push_back(v[i].first);
		}
	}

	cout << ans.size() << '\n';
	while (!ans.empty())
	{
		cout << ans.back() << '\n';
		ans.pop_back();
	}

	return 0;
}