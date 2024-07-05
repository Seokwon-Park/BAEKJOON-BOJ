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

	string s;
	cin >> s;
	int p = stoi(s.substr(2));
	int q = stoi('1' + string(s.size() - 2, '0'));
	cout << "YES\n";
	cout << p << ' ' << q;

	return 0;
}