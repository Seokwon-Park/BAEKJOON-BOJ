//xor로 무조건 b를 만들 수 있음
//여기서 1회는 무조건 b를 만드는데 써야하므로 (n-1)턴의 경우의 수가 필요함
//카드의 총 개수는 2^31이므로 2^31개를 중복가능하게 n-1번 뽑는다고 가정하면 (2^31)^(n-1)
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, n;
	cin >> a >> b >> n;

	ll x = (1LL << 31) %MOD;
	ll exp = n - 1;
	ll ans = 1;
	while (exp)
	{
		if (exp % 2)
		{
			ans *= x;
			ans %= MOD;
		}
		x *= x;
		x %= MOD;
		exp /= 2;
	}

	cout << ans;

	return 0;
}