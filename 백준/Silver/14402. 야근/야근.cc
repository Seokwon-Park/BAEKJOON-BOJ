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
	
	Hash<string, int> h;
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		string name;
		char c;
		cin >> name >> c;
		if (h[name] == 0 && c == '-')
		{
			ans++;
		}
		else
		{
			if (c == '-') h[name]--;
			else h[name]++;
		}
	}
	
	for (auto [name, in] : h)
	{
		ans += in;
	}
	cout << ans;
		
	return 0;
}