#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

bool v[360];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> angles(n);
	for (int i = 0; i < n; i++)
	{
		cin >> angles[i];
	}

	queue<int> q;
	q.push(0);
	v[0] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			int nxt = (cur + angles[i]) % 360;
			int nxt2 = (cur + (360 - angles[i])) % 360;
			if (!v[nxt])
			{
				v[nxt] = true;
				q.push(nxt);
			}
			if (!v[nxt2])
			{
				v[nxt2] = true;
				q.push(nxt2);
			}
		}
	}

	for (int i = 0; i < k; i++)
	{
		int angle;
		cin >> angle;

		if (v[angle])
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}