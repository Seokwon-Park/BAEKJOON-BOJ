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
	 
	while (1)
	{
		int n;
		cin >> n;
		if (n == -1) break;
		int res = 1;
		vector<int> v(1, 1);
		for (int i= 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (n / i == i)
				{
					v.push_back(i);
					res += i;
				}
				else
				{
					v.push_back(i);
					v.push_back(n / i);
					res += i + n / i;
				}
			}
		}
		if (res == n)
		{
			cout << res << " = ";
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
			{
				if (i == 0)
				{
					cout << v[i];
				}
				else
				{
					cout << " + " << v[i];
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect.";
		}
		cout << '\n';

	}

	return 0;
}