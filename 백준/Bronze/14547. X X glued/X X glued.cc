#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		string a, b, c;
		cin >> a;
		if (a == "#")break;
		cin >> b >> c;
		int ix = 0;
		set<int> answer;
		while (ix < 3)
		{
			if (b[ix] == b[ix + 1])
			{
				answer.insert(b[ix] - '0');
				ix += 2;
			}
			else
				ix++;
		}
		if (!answer.empty())
		{
			vector<int> cpy(answer.begin(), answer.end());
			if (cpy.size() == 1)
			{
				cout << cpy[0] << ' ' << cpy[0] << " glued\n";
			}
			else
				cout << cpy[0] << ' ' << cpy[0] << " glued and "<< cpy[1] << ' ' << cpy[1] << " glued\n";

		}
	}

	return 0;
}