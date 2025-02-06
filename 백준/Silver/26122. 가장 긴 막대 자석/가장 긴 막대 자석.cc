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
	string s;
	cin >> s;
	char prev = s[0];
	int cont = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (prev == s[i])
		{
			cont++;
		}
		else
		{
			v.push_back(cont);
			prev = s[i];
			cont = 1;
		}
	}
	v.push_back(cont);

	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		ans = max(ans, min(v[i],v[i+1])*2);
	}
	cout << ans;



	return 0;
}



