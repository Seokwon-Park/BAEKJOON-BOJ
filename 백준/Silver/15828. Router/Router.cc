#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;
	int n;
	cin >> n;
	while (1)
	{
		int m;
		cin >> m;
		if (m == -1)break;
		if (m != 0)
		{
			if (q.size() < n)
				q.push(m);
		}
		else if (m == 0)
		{
			q.pop();
		}
	}

	if (q.empty())
	{
		cout << "empty";
		return 0;
	}

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}