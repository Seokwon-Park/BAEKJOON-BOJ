#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

void flip(string& s, int ix)
{
	if (ix >= s.size() || ix < 0) return;
	if (s[ix] == '0')
		s[ix] = '1';
	else
		s[ix] = '0';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string case1;
	string case2;
	string s;
	cin >> case1 >> s;
	case2 = case1;
	
	int res1= 0;
	int res2= 0;

	flip(case1, 0);
	flip(case1, 1);
	res1++;

	for (int i = 1; i < n; i++)
	{
		if (case1[i-1] != s[i-1] )
		{
			flip(case1, i - 1);
			flip(case1, i);
			flip(case1, i + 1);
			res1++;
		}

		if (case2[i - 1] != s[i - 1])
		{
			flip(case2, i - 1);
			flip(case2, i);
			flip(case2, i + 1);
			res2++;
		}
	}
	int ans = INT_MAX;

	if (case1 == s && case2 == s)
	{
		ans = min(res1, res2);
	}
	else if (case1 == s)
	{
		ans = res1;
	}
	else if (case2 == s)
	{
		ans = res2;
	}
	else
	{
		ans = -1;
	}
	cout << ans;

	return 0;
}