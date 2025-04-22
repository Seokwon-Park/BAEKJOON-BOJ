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

	int a, b, c;
	cin >> a >> b >> c;
	int d, e, f;
	cin >> d >> e >> f;

	int abcmx = max({ a,b,c });
	int abcleft = a + b + c - abcmx;
	int defmx = max({ d,e,f });
	int defleft = d + e + f - defmx;
	cout << abcleft + defleft + abs(abcmx - defmx);

	
	return 0;
}