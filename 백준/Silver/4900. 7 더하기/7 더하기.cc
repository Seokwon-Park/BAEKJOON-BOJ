#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

map<string, int> bton;
string ntob[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bton["063"] = 0;
	bton["010"] = 1;
	bton["093"] = 2;
	bton["079"] = 3;
	bton["106"] = 4;
	bton["103"] = 5;
	bton["119"] = 6;
	bton["011"] = 7;
	bton["127"] = 8;
	bton["107"] = 9;

	ntob[0] = "063";
	ntob[1] = "010";
	ntob[2] = "093";
	ntob[3] = "079";
	ntob[4] = "106";
	ntob[5] = "103";
	ntob[6] = "119";
	ntob[7] = "011";
	ntob[8] = "127";
	ntob[9] = "107";

	while (1)
	{
		string s;
		cin >> s;
		if (s == "BYE")break;
		int ix = 0;
		int a = 0;
		while (s[ix] != '+')
		{
			a = a * 10 + bton[s.substr(ix, 3)];
			ix += 3;
		}
		ix++;
		int b = 0;
		while (s[ix] != '=')
		{
			b = b * 10 + bton[s.substr(ix, 3)];
			ix += 3;
		}

		int res = a + b;
		string ans = "";
		while (res)
		{
			ans = ntob[res % 10] + ans;
			res /= 10;
		}
		cout << s << ans << '\n';
	}
	


	return 0;
}