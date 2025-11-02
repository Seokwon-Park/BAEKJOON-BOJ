
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

	ll n;
	while (cin >> n)
	{
		ll p = 1;
		bool b = true;

		while (p < n)
		{
			if (b)
			{
				p *= 9; // 백준이 9를 곱하면 이길 수 있나?
			}
			else
			{
				p *= 2; // 동혁이가 2를 곱해도 이기나?
			}
			b = !b;
		}

		if (!b)
		{
			cout << "Baekjoon wins.";
		}
		else
		{
			cout << "Donghyuk wins.";
		}
		cout << '\n';
	}

	return 0;
}
