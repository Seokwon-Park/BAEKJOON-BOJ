#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int res;
int n;
int ans;

void func(int k)
{
	if (k == n)
	{
		ans += (res % 3 == 0) ? 1 : 0;
		return;
	}
	if (k != 0)
	{
		func(k + 1);
	}
	res += 1;
	func(k + 1);
	res -= 1;

	res += 2;
	func(k + 1);
	res -= 2;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << ans;
	
	return 0;
}
