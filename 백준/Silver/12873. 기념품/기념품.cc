#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	for (ll i = 1; i <= n-1; i++)
	{
		int m = (i*i*i-1) %(q.size());
		while (m--)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		q.pop();
	}

	cout << q.front();

	return 0;
}