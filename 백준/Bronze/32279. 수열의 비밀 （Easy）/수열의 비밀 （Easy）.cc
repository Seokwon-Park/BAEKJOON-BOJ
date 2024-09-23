#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n;
int p, q, r, s;
int a1;
int arr[21];

void init(int ix, int val)
{
	if (ix > n) return;
	arr[ix] = val;
	init(ix * 2, p * val + q);
	init(ix * 2+1, r * val+ s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> p >> q >> r >> s;
	cin >> a1;

	init(1, a1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += arr[i];
	}

	cout << ans;

	return 0;
}
