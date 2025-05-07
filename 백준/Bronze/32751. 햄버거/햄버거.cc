#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int aa = 0;
	int bb = 0;
	int cc = 0;
	int dd = 0;

	int prev = '\0';
	bool isGood = true;
	for (auto ch : s)
	{
		if (ch != prev)
		{
			prev = ch;
		}
		else
		{
			isGood = false;
			break;
		}
		switch(ch)
		{
		case 'a':
			aa++;
			break;
		case 'b':
			bb++;
			break;
		case 'c':
			cc++;
			break;
		case 'd':
			dd++;
			break;
		}
	}

	bool isbread = s[0] == 'a' && s[n - 1] == 'a';

	if (isGood == false || aa > a || bb > b || cc > c || dd > d ||isbread == false)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}

	return 0;
}