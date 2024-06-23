#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		cin >> s;
		if (s == "P=NP")
		{
			cout << "skipped\n";
			continue;
		}
		istringstream iss(s);
		string ss;
		int res = 0;
		while (getline(iss, ss, '+'))
		{
			res += stoi(ss);
		}
		cout << res << '\n';

	}

	return 0;
}