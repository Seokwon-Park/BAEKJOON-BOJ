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

	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "#")break;
		vector<int>v(26, 0);
		for (auto c : s)
		{
			if (isalpha(c))
			{
				c = tolower(c);
				v[c - 'a']++;
			}
		}

		cout << count_if(v.begin(), v.end(), [](const auto a) {return a > 0; }) << '\n';
	}


	return 0;
}