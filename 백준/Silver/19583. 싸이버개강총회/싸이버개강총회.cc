#include <bits/stdc++.h>

using namespace std;

int tti(string hm)//time to int;
{
	int hour = stoi(hm.substr(0, 2));
	int min = stoi(hm.substr(3, 2));

	return hour * 60 + min;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> um; //name, state( 0 = not joined, 1 = joined, 2 = quit)

	string s, e, q;
	cin >> s >> e >> q;
	int ss = tti(s);
	int ee = tti(e);
	int qq = tti(q);

	int answer = 0;
	string ti, name;
	while (cin >> ti >> name)
	{
		int tm = tti(ti);
		if (tm <= ss)
		{
			um[name] = 1;
		}
		if (tm >= ee && tm <= qq)
		{
			if (um[name] == 1)
			{
				um[name] = 2;
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}