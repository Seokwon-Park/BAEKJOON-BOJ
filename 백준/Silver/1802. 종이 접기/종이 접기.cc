#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

bool check(int l, int r, string& s)
{
	if (l == r) return true;
	int mid = (l + r) / 2;
	string lstring = s.substr(0, (r-l)/2);
	string rstring = s.substr(mid + 1, (r - l) / 2);
	reverse(rstring.begin(), rstring.end());
	for (auto& c : rstring)
	{
		if (c == '0') c = '1';
		else c = '0';
	}
	bool res = (lstring == rstring);

	res &= check(l, mid - 1, s);
	res &= check(mid + 1, r, s);

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;

		cout << (check(0, s.size() - 1, s) ? "YES" : "NO");
		cout << '\n';
	}

	return 0;
}

