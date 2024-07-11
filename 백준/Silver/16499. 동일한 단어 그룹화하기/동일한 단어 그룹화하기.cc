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
	set<string>s;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		s.insert(str);
	}
	cout << s.size();


	return 0;
}
