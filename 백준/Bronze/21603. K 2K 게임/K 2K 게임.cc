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
	
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		int fx = i % 10;
		int fk = k % 10;
		int f2k = k * 2 % 10;
		if (fx != fk && fx != f2k)
		{
			cnt++;
			ans.push_back(i);
		}
	}
	cout << cnt << '\n';
	for (auto i : ans)
	{
		cout << i << ' ';
	}
	

	return 0;
}