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

	int n, k, m;
	cin >> n >> k >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	bool isRev = false;
	int removed = 0;
	while (!dq.empty())
	{
		for (int i = 0; i < k-1; i++)
		{
			if (!isRev)
			{
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			else
			{
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
		if (isRev)
		{
			cout << dq.back();
			dq.pop_back();
		}
		else
		{
			cout << dq.front();
			dq.pop_front();
		}
		cout << '\n';
		removed++;
		if (removed == m)
		{
			isRev = !isRev;
			removed = 0;
		}
	}
	

	return 0;
}