#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}

	cout << (sum + 300 <= 1800 ? "Yes" : "No");

	return 0;
}