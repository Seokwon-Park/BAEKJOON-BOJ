#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<ll> fibo(2);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fibo[0] = 0;
	fibo[1] = 1;
	int ix = 2;
	while (fibo[ix - 1] + fibo[ix - 2] <= 1e9)
	{
		fibo.push_back(fibo[ix - 1] + fibo[ix - 2]);
		ix++;
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> ans;
		while (n)
		{
			for (int i = fibo.size() - 1; i >= 0; i--)
			{
				if (fibo[i] <= n)
				{
					n -= fibo[i];
					ans.push_back(fibo[i]);
					break;
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (auto i : ans)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}