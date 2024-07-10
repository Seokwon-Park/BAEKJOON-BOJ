#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

bool isDead[505];
int mo[505];
int fa[505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> mo[i] >> fa[i];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		isDead[k] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!isDead[i] && mo[i] != 0 && fa[i] != 0 && !isDead[mo[i]] && !isDead[fa[i]]) // 본인이 안죽었고, 부모가 0이 아니고, 부모가 0이 아니어도 죽은 상태가 아니면 행-복
			ans++;
	}

	cout << ans;

	return 0;
}