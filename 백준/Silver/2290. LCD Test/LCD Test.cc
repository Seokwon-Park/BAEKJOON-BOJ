#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool top[10] = { 1,0,1,1,0,1,1,1,1,1 };
bool topleft[10] = { 1,0,0,0,1,1,1,0,1,1 };
bool topright[10] = { 1,1,1,1,1,0,0,1,1,1 };
bool mid[10] = { 0,0,1,1,1,1,1,0,1,1 };
bool botleft[10] = { 1,0,1,0,0,0,1,0,1,0 };
bool botright[10] = { 1,1,0,1,1,1,1,1,1,1 };
bool bot[10] = { 1,0,1,1,0,1,1,0,1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s;
	string n;
	cin >> s >> n;

	for (int i = 0; i < 2 * s + 3; i++)
	{
		for (int j = 0; j < n.size(); j++)
		{
			int num = n[j] - '0';
			if (i == 0)
			{
				if (top[num])
				{
					cout << ' ';
					for (int k = 0; k < s; k++)
						cout << '-';
					cout << ' ';
				}
				else
				{
					for (int k = 0; k < s+2; k++)
						cout << ' ';
				}

			}
			if (i > 0 && i < s + 1)
			{
				if (topleft[num])
					cout << '|';
				else
					cout << ' ';
				for (int k = 0; k < s; k++)
					cout << ' ';
				if (topright[num])
					cout << '|';
				else
					cout << ' ';
			}
			if (i == s+1)
			{
				if (mid[num])
				{
					cout << ' ';
					for (int k = 0; k < s; k++)
						cout << '-';
					cout << ' ';
				}
				else
				{
					for (int k = 0; k < s + 2; k++)
						cout << ' ';
				}
			}
			if (i > s+1 && i < 2*s + 2)
			{
				if (botleft[num])
					cout << '|';
				else
					cout << ' ';
				for (int k = 0; k < s; k++)
					cout << ' ';
				if (botright[num])
					cout << '|';
				else
					cout << ' ';
			}
			if (i == 2*s + 2)
			{
				if (bot[num])
				{
					cout << ' ';
					for (int k = 0; k < s; k++)
						cout << '-';
					cout << ' ';
				}
				else
				{
					for (int k = 0; k < s + 2; k++)
						cout << ' ';
				}
			}
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}