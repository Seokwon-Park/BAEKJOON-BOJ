#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


//애드혹
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	bool isInc = true;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	if (n == 1)
	{
		cout << "YES\n";
		cout << -1 << '\n' << v[0] + 1 << '\n';
	}
	else
	{
		int gap = v[1] - v[0];
		for (int i = 2; i < n; i++)
		{
			if (v[i] - v[i - 1] != gap)
			{
				cout << "NO\n";
				isInc = false;
				break;
			}
		}
		if (isInc)
		{
			cout << "YES\n";
			int a1 = v[0] + 1;
			int a2 = -1;
			for (int i = 0; i < n; i++)
			{
				cout << a1 + (gap + 1) * i << ' ';
			}
			cout << '\n';
			for (int i = 0; i < n; i++)
			{
				cout << a2 + (-1) * i << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}

