#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 참고한 풀이힌트 - 1000원 짜리를 매일 먹는다는 가정을 가지고 시작할 것
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<pii> v;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		ans += b;
		x -= 1000;
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return a.first - a.second > b.first - b.second;
		}
	);

	
	for (int i = 0; i < n; i++)
	{
		if (x >= 4000 && v[i].first - v[i].second > 0)
		{
			ans += v[i].first - v[i].second;
			x -= 4000;
		}
		else
			break;
	}
	cout << ans;

	return 0;
}