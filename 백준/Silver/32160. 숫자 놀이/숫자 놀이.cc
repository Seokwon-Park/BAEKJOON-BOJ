#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	if (n / 2 % 2 == 0)
	{
		cout << n;
	}
	else
	{
		cout << n - 1;
	}

	if (n == 1) return 0;
	cout << '\n';
	queue<int> q;
	if (n % 2 == 0)
	{
		q.push(1);
		for (int i = 1; i <= (n - 1) / 2; i++)
		{
			cout << i * 2 << ' ' << i * 2 + 1 << '\n';
			q.push(1);
		}
	}
	else
	{
		for (int i = 0; i < (n - 1) / 2; i++)
		{
			cout << i * 2 + 1 << ' ' << i * 2 + 2 << '\n';
			q.push(1);
		}
	}
	
	while (q.size() > 1)
	{
		int a = q.front();
		q.pop();
		int b = q.front();
		cout << a << ' ' << b << '\n';
		q.pop();
		q.push(abs(a - b));
	}

	cout << q.front() << ' ' << n;
	


	
	return 0;
}