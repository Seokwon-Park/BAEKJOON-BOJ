#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		string n;
		cin >> n;
		if (n == "0") break;
		string res = n;
		
		while (res.size() != 1)
		{
			int tmp = 0;
			for (auto c : res)
			{
				tmp += c - '0';
			}
			res = to_string(tmp);
		}
		cout << res << '\n';
	}

	return 0;
}