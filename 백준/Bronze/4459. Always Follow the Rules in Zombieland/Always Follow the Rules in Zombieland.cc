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
	cin.ignore();
	vector<string> rule(n);
	for (int i = 0; i < n; i++)
	{
		getline(cin, rule[i]);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		cout << "Rule " << x << ": ";
		if (x > 0 && x <= n)
		{
			cout << rule[x - 1];
		}
		else
		{
			cout << "No such rule";
		}
		cout << '\n';
	}

	return 0;
}