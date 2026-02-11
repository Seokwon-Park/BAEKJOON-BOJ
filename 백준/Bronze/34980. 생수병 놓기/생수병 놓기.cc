
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
	string a, b;
	cin >> a >> b;
	if (a == b) cout << "Good";
	
	else
	{
		int acnt = count(a.begin(), a.end(), 'w');
		int bcnt = count(b.begin(), b.end(), 'w');
		if (acnt < bcnt) cout << "Manners maketh man";
		else if (acnt == bcnt) cout << "Its fine";
		else cout << "Oryang";
	}

	return 0;
}