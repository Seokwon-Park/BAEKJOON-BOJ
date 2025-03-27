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

	int n, a, b;
	cin >> n >> a >> b;
	int aa = 66 - a;
	int bb = 130 - b;

	vector<pii> v;
	for (int i = 0; i < 10; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < 8-n; i++)
	{
		auto [x, y] = v[i];
		
		aa -= 3 * x;
		bb -= 3 * x;
		bb -= 3 * min((6 - x), y);
	}

	if (aa <= 0&& bb <= 0)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Nae ga wae";
	}

	return 0;
}