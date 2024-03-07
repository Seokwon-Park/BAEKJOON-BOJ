#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<vector<string>> s;
	int lcnt = 0;
	int rcnt = 0;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == ")")
		{
			rcnt++;
			vector<vector<long long>> cba;
			while (!s.empty())
			{
				if (s.top()[0] == "(")
				{
					s.pop();
					break;
				}
				cba.push_back({ stoll(s.top()[0]), stoll(s.top()[1])}); // index 0:c 1:b 2:a
				s.pop();
			}
			if (cba.size() != 3)
			{
				cout << -1;
				return 0;
			}
			vector<long long> res(2);
			res[0] = cba[1][0] * cba[0][1]; //분자
			res[1] = cba[0][0] * cba[1][1]; //분모
			int g = gcd(res[0], res[1]);
			res[0] /= g;
			res[1] /= g;
			int l = lcm(res[1], cba[2][1]);
			res[0] = res[0] * (l / res[1]) + cba[2][0] * (l / cba[2][1]);
			res[1] = l;
			g = gcd(res[0], res[1]);
			res[0] /= g;
			res[1] /= g;
			
			s.push({ to_string(res[0]), to_string(res[1]) });
		}
		else
		{
			if (input == "(")
			{
				lcnt++;
			}
			s.push({ input, "1" });
		}
	}

	if (lcnt != rcnt || s.size() != 1)
		cout << -1;
	else
		cout << s.top()[0] << ' ' << s.top()[1];

	return 0;
}