#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_map<string, int> um;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		string a;
		int b;

		cin >> a >> b;
		um[a] = b;
		if (a == "jinju")
		{
			ans = b;
		}
	}

	vector<pair<string, int>> v(um.begin(), um.end());
	cout << ans << '\n';
	cout << count_if(v.begin(), v.end(), [ans](auto A) {
		return A.second > ans;
		});

	return 0;
}