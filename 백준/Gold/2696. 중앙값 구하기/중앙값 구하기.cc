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

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> ans;
		priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq2;
		for (int i = 1; i <= n; i++)
		{

			int x; cin >> x;

			if (pq.empty())
			{
				pq.push(x);
			}
			else
			{
				if (pq.top() < x)
				{
					pq2.push(x);
				}
				else
				{
					pq.push(x);
				}
			}

			if (i % 2 == 1)
			{
				while (pq.size() != pq2.size() + 1)
				{
					if (pq.size() > pq2.size())
					{
						pq2.push(pq.top());
						pq.pop();
					}
					else
					{
						pq.push(pq2.top());
						pq2.pop();
					}
				}
				ans.push_back(pq.top());
			}
		}

		cout << ans.size() << '\n';
		int cnt = 0;
		for (auto i : ans)
		{
			cout << i << ' ';
			cnt++;
			if (cnt == 10)
			{
				cout << '\n';
				cnt = 0;
			}
		}
		cout << '\n';
	}


	return 0;
}