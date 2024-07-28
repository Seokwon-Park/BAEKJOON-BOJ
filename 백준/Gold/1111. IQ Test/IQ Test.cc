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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}



	if (n == 1)
	{
		cout << 'A';
	}
	else if( n== 2)
	{
		if (v[0] == v[1])
			cout << v[0];
		else
			cout << "A";
	}
	else
	{

		int a = 0;
		int b = 0;
		int ans = 0;
		for (int i = 0; i <= 200; i++)
		{
			bool isRight = true;
			for (int j = 0; j < n - 2; j++)
			{
				int a1 = v[j] * i;
				int a2 = v[j + 1] * i;
				if (v[j + 1] - a1 != v[j + 2] - a2)
				{
					isRight = false;
					break;
				}
			}
			if (isRight)
			{
				ans++;
				a = i;
				b = v[1] - v[0] * a;
			}
		}

		int na = 0;
		int nb = 0;
		int nans = 0;
		for (int i = -1; i >= -200; i--)
		{
			bool isRight = true;
			for (int j = 0; j < n - 2; j++)
			{
				int a1 = v[j] * i;
				int a2 = v[j + 1] * i;
				if (v[j + 1] - a1 != v[j + 2] - a2)
				{
					isRight = false;
					break;
				}
			}
			if (isRight)
			{
				nans++;
				na = i;
				nb = v[1] - v[0] * na;
			}
		}
		if (ans == 0 && nans == 0)
			cout << "B";
		else if (ans > 0)
		{
			cout << v[n - 1] * a + b;
		}
		else if (nans > 0)
		{
			cout << v[n - 1] * na + nb;
		}
		else
			cout << "A";
	}


	return 0;
}