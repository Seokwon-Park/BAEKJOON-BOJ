#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	stack<pii> st;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (i % 2 == 1)
		{
			if (st.empty())
			{
				st.push({ x,1 });
			}
			else
			{
				auto [y, cnt] = st.top();
				if (y == x)
				{
					st.pop();
					st.push({ x, cnt + 1 });
				}
				else
				{
					st.push({ x, 1 });
				}
			}
		}
		else
		{
			auto [y, cnt] = st.top();
			st.pop();
			if (!st.empty())
			{
				if (st.top().first == x)
				{
					auto [z, cnt2] = st.top();
					st.pop();
					st.push({ x, cnt + 1 + cnt2 });
				}
				else
				{
					st.push({ x, cnt + 1 });
				}
			}
			else
			{
				st.push({ x, cnt + 1 });
			}
		
		}
	}

	int ans = 0;
	while (!st.empty())
	{
		auto [y, cnt] = st.top();
		st.pop();
		if (y == 0)
		{
			ans += cnt;
		}
	}

	cout << ans;



	return 0;
}