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
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'A')
			{
				a++;
			}
		}
		if (a != 1)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	
	return 0;
}
