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

	int n, m;
	cin >> n >> m;

	vector<int> vr(m);
	vector<int> vc(m);
	for (int i = 0; i < m; i++)
	{
		int r, c;
		cin >> r >> c;
		vr[i] = r;
		vc[i] = c;
	}

	sort(vr.begin(), vr.end());
	sort(vc.begin(), vc.end());

	int rmid = vr[m / 2];
	int cmid = vc[m / 2];
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += abs(vr[i] - rmid);
		ans += abs(vc[i] - cmid);
	}
	cout << ans;

	return 0;
}