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

	for (int i = 0; i < n + 2; i++)
		cout << '@';
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << '@';
		for (int j = 0; j < n; j++)
			cout << ' ';
		cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < n + 2; i++)
		cout << '@';

	return 0;
}