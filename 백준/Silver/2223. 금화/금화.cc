#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, x, m;
	cin >> t >> x >> m;
	vector<int> mon; // 몇 단위 시간까지 ㄱㅊ은지
	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
		mon.push_back(d / s - (d % s == 0 ? 1 : 0));
	}

	sort(mon.begin(), mon.end()); // 몬스터가 도달하는데 가장 짧은 시간을 구하려고,

	if (mon.empty()) // 몬스터가 없으면 그냥 주어진 시간에 주우면 됨.
	{
		cout << t * x;
		return 0;
	}
	if (mon[0] == 0)
	{
		cout << 0;
		return 0;
	}

	int ans = 0;
	ans += min(t, mon[0]) * x; // 일단 접근하기 직전까지 주움.
	t -= mon[0] + 1; // 접근하기 직전까지의 시간 + 다시 한번 떨어뜨려줌.
	t = max(0, t);

	int left_ = t / 2 + (t % 2 == 0 ? 0 : 1); // 캤다가 쉬었다가 하면 최대치만큼 모으는 경우가된다.
	ans += left_ * x;

	cout << ans;

	return 0;
}