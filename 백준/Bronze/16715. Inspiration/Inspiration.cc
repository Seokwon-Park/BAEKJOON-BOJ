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

	int n;
	cin >> n;
	int ans = 0;
	int num = 0;
	for (int i = n; i >= 2; i--)
	{
		int result = 0;
		int tmp = n;
		while (tmp)
		{
			result += tmp % i;
			tmp /= i;
		}
		if (result >= ans)
		{
			num = i;
			ans = result;
		}
	}
	cout << ans << ' ' << num;



	return 0;
}



