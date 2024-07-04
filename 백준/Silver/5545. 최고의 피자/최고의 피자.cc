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

	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int c;
	cin >> c;

	int cost = a;
	int curkal = c;
	vector<int> toppin(n);
	for (int i = 0; i < n; i++)
	{
		cin >> toppin[i];
	}
	sort(toppin.begin(), toppin.end(), greater<int>());

	for (int i = 0; i < n; i++)
	{
		if ((curkal + toppin[i]) / (cost + b) >= curkal / cost)
		{
			curkal += toppin[i];
			cost += b;
		}
	}
	cout << curkal / cost;




	return 0;
}
