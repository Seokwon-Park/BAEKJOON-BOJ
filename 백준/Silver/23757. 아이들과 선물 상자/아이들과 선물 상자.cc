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
	
	int n, m;
	cin >> n >> m;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		pq.push(k);
	}

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		int box = pq.top();
		pq.pop();
		if (k > box || pq.empty())
		{
			cout << 0;
			return 0;
		}
		else
		{
			box -= k;
			if (box != 0)
			{
				pq.push(box);
			}
		}
	}

	cout << 1;

	return 0;
}