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

	string s;
	cin >> s;
	bool isLeft = true;
	int l = 0;
	int r = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isLeft)
		{
			if (s[i] == '@')
				l++;
		}
		else
		{
			if (s[i] == '@')
				r++;
		}
		if (s[i] == '(')
			isLeft = false;

	}
	cout << l << ' ' << r;

	return 0;
}