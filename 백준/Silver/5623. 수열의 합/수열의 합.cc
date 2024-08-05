#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}
	
	if (n == 2)
	{
		cout << "1 1";
		return 0;
	}
	
	vector<int> ans(n);
	ans[0] = (b[0][1] - b[1][2] + b[0][2]) / 2;
	for (int i = 1; i < n; i++)
	{
		ans[i] = b[0][i] - ans[0];
	}

	for (auto i : ans)
		cout << i << ' ';


	return 0;
}