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
	int n;
	cin >> n;

	int back = n+1;
	int maxSize = 0;
	deque<int> dq;
	for (int i = 0; i < n; i++)
	{
		int cmd; 
		cin >> cmd;
		if (cmd == 1)
		{
			int m;
			cin >> m;
			dq.push_back(m);
		}
		else
		{
			dq.pop_front();
		}

		if (dq.size() > maxSize)
		{
			back = dq.back();
			maxSize = dq.size();
		}
		else if (dq.size() == maxSize)
		{
			if (back > dq.back())
			{
				back = dq.back();
			}
		}
	}

	cout << maxSize << ' ' << back;

	return 0;
}