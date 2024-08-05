#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

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

	vector<int> ans(n);
	ans[0] = v[0];
	ans[n-1] = v[n-1];
	for (int i = 1; i < n - 1; i++)
	{
		int up = min(v[i - 1], v[i + 1]);
		ans[i] = v[i] + up;
	}

	cout << *max_element(ans.begin(), ans.end());


	return 0;
}