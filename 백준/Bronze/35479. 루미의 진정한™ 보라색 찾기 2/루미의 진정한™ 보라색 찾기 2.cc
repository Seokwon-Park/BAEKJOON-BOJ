#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	int rgb[3];
	for (auto& i : rgb)cin >> i;
	double rgbprime[3];
	for (int i = 0; i < 3; i++)
	{
		rgbprime[i] = rgb[i] / 255.0;
	}

	double k = 1 - *max_element(rgbprime, rgbprime + 3);

	for (int i = 0; i < 3; i++)
	{
		if (k == 1)
			cout << 0 << ' ';
		else
			cout << fixed << setprecision(4) << (1 - rgbprime[i] - k) / (1 - k) << ' ';
	}

	cout << fixed << setprecision(4) << k;

	return 0;
}