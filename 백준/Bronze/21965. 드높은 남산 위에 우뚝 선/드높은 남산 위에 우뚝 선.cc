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
	bool isDec = false;
	
	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (!isDec)
		{
			if (prev == m)
			{
				cout << "NO";
				return 0;
			}
			else if(prev > m)
			{
				isDec = true;
			}
		}
		else
		{
			if (prev <= m)
			{
				cout << "NO";
				return 0;
			}
		}
		prev = m;
	}

	cout << "YES";

	return 0;
}
