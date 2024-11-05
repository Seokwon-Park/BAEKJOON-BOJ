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

	string ans = "";
	for (int i = 0; i < k-1; i++)
	{
		ans += 'b' + i;
	}

	string a(n - k + 1, 'a');
	cout << a + ans;


	return 0;
}
