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
	string s;
	cin >> n >> s;
	int ans = 0;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string name, chat;
		cin >> name >> chat;
		if (name == s)
		{
			ans = m[chat];
		}
		m[chat]++;
		
	}
	cout << ans;

	

	return 0;
}