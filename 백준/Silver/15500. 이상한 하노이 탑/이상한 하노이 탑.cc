#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> s1, s2;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s1.push_back(x);
	}

	vector<pair<int, int>> ans;

	int order = n;

	while (order)
	{
		if (!s1.empty() && s1.end() != find(s1.begin(), s1.end(), order))
		{
			while (s1.back() != order)
			{
				ans.push_back({ 1, 2 });
				s2.push_back(s1.back());
				s1.pop_back();
			}

			ans.push_back({ 1, 3 });
			s1.pop_back();
			order--;
		}
		else if (!s2.empty() && s2.end() != find(s2.begin(), s2.end(), order))
		{
			while (s2.back() != order)
			{
				ans.push_back({ 2, 1 });
				s1.push_back(s2.back());
				s2.pop_back();
			}

			ans.push_back({ 2, 3 });
			s2.pop_back();
			order--;
		}
	}

	cout << ans.size() << '\n';
	for (auto [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	
	return 0;
}