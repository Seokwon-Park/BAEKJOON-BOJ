#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> up(n), down(n);

	for (int i = 0; i < n; i++)cin >> up[i];
	for (int i = 0; i < n; i++)cin >> down[i];
	int cury = 0;

	for (int i = 0; i < n; i++)
	{
		if (cury >= up[i])
		{
			cury = up[i] - 1;
		}
		else if (cury <= down[i])
		{
			cury = down[i] + 1;
		}
		cout << cury << ' ';
	}


	return 0;
}