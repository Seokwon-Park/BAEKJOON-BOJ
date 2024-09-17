#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool isOpened[21];
int a, b;
int order[20];
int n, m;
int ans = INF;

void func(int a, int b, int k, int moved)
{
	int toOpen = order[k];

	if (k == m)
	{
		ans = min(ans, moved);
		return;
	}

	func(toOpen, b, k+1, moved + abs(toOpen - a));
	func(a, toOpen, k+1, moved+ abs(toOpen - b));

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> a >> b;
	isOpened[a] = true;
	isOpened[b] = true;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> order[i];
	}

	func(a, b, 0, 0);
	
	cout << ans;

	return 0;
}