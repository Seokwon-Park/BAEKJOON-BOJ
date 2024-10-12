#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (v[i] % 2 != i % 2)
		{
			cout << "NO";
			return 0;
		}
			
	}

	cout << "YES";

	return 0;
}