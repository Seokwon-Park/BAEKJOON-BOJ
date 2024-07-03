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
	priority_queue<int> mxpq;
	priority_queue<int, vector<int>, greater<int>> mnpq;
	int right = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (mxpq.empty())
		{
			mxpq.push(m);
		}
		else
		{
			if (m > mxpq.top())
			{
				if (mnpq.empty())
					mnpq.push(m);
				else
				{
					mnpq.push(m);
					while (mxpq.size() < mnpq.size())
					{
						mxpq.push(mnpq.top());
						mnpq.pop();
					}
				}
			}
			else
			{
				while (mxpq.size() > mnpq.size())
				{
					mnpq.push(mxpq.top());
					mxpq.pop();
				}
				mxpq.push(m);
			}
		}
		cout << mxpq.top() << '\n';
	}

	return 0;
}