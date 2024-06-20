#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, k;
	cin >> n >> x >> k;
	vector<bool> cups(n + 1, false);
	cups[x] = true;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		swap(cups[a], cups[b]);
	}
	cout << find(cups.begin(), cups.end(), true) - cups.begin();


	return 0;
}