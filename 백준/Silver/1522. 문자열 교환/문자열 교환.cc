#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int needSwap(int st, int en, string& s)
{
	int b = 0;
	for (int i = st; i <= en; i++)
	{
		if (s[i] == 'b')
			b++;
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int a = 0;
	for (char c : s)
	{
		if (c == 'a')
			a++;
	}

	if (a == 0)
	{
		cout << 0;
		return 0;
	}
	s += s.substr(0, a);
	
	int st = 0;
	int en = a-1;

	int ans = INT_MAX;
	while (en < s.size())
	{
		ans = min(ans, needSwap(st, en, s));
		st++; 
		en++;
	}
	cout << ans;
	
	return 0;
}