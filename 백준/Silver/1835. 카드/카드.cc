#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int> dq;
	
	for (int i = n; i >= 1; i--)
	{
		dq.push_front(i);
		if (dq.size() > 1)
		{
			for (int j = 0; j < i; j++)
			{
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}

	for (auto i : dq)
		cout << i << ' ';

	return 0;
}
