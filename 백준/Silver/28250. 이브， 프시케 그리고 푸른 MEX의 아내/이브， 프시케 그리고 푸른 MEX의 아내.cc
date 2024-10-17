#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll v[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ai;
		cin >> ai;
		v[ai]++;
	}

	
	// 약간 애드혹 느낌? (0,0) 1점 , (0,1)2점 , (0,2)1점... ... (0,x)1점..
	// 0이 들어가는 경우 외에는 다 0점을 가지게 된다. {a,b}를 제외한 가장 작은 음이아닌 정수이므로.

	ll ans = 0;
	for (int i = 0; i <= 100000; i++)
	{
		if (v[i] == 0) continue;
		if (i == 0)
		{
			ans += v[i] * (v[i] - 1) / 2;
		}
		else if (i == 1)
		{
			ans += v[i] * v[0] * 2; // 2점
		}
		else
		{
			ans += v[i] * v[0] * 1;
		}
	}

	cout << ans;


	return 0;
}