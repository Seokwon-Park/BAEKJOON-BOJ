#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	if (n % k == 0)
	{
		cout << 0;
	}
	else
	{
		if (k > n / 2)
		{
			k = n - k;
		}
		ll g = gcd(n, k);
		n /= g;
		k /= g;

		// 1...1+k 사이의 점의 개수 = (1+k) - 1 - 1 = k-1
		// 각 점이 생기는 교점 2개
		// 그러나 두 교차하는 직선의 순서는 상관없으므로 / 2
		// 서로소인 총 대각선의 개수는 n개
		cout << n * (k - 1);
	}

	return 0;
}