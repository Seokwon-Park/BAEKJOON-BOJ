#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string a, b;
		cin >> a >> b;
		vector<int> dday;
		vector<int> curday;
		istringstream iss(a);
		istringstream iss2(b);
		string tmp;
		while (getline(iss, tmp, '/'))
		{
			dday.push_back(stoi(tmp));
		}

		while (getline(iss2, tmp, '/'))
		{
			curday.push_back(stoi(tmp));
		}

		int dd = days[dday[0]] + dday[1];
		int cd = days[curday[0]] + curday[1];

		if (dday[2] % 4 == 0)
		{
			if (dday[2] % 100 != 0 || dday[2] % 400 == 0)
			{
				if (dday[0] > 2)
				{
					dd++;
				}
				if (curday[0] > 2)
				{
					cd++;
				}
			}
		}
		if (cd == dd)
		{
			cout << "SAME DAY";
		}
		else if (abs(cd - dd) <= 7)
		{
			if (abs(cd - dd) > 1)
			{
				if (dd < cd)
				{
					cout << b << '/' << dday[2] << " IS " << cd - dd << " DAYS AFTER";
				}
				else if (dd > cd)
				{
					cout << b << '/' << dday[2] << " IS " << dd - cd << " DAYS PRIOR";
				}
			}
			else
			{
				if (dd < cd)
				{
					cout << b << '/' << dday[2] << " IS " << cd - dd << " DAY AFTER";
				}
				else if (dd > cd)
				{
					cout << b << '/' << dday[2] << " IS " << dd - cd << " DAY PRIOR";
				}
			}

		}
		else
		{
			if (dd < cd)
			{
				dd += 365;
				if (dday[2] % 4 == 0)
				{
					if (dday[2] % 100 != 0 || dday[2] % 400 == 0)
					{
						if (curday[0] > 2)
						{
							cd--;
						}
					}
				}
				if (dd - cd > 1)
				{
					if (dd - cd <= 7)
					{
						cout << b << '/' << dday[2] - 1 << " IS " << dd - cd << " DAYS PRIOR";
					}
					else
					{
						cout << "OUT OF RANGE";
					}
				}
				else
				{
					if (dd - cd <= 7)
					{
						cout << b << '/' << dday[2] - 1 << " IS " << dd - cd << " DAY PRIOR";
					}
					else
					{
						cout << "OUT OF RANGE";
					}
				}
			}
			else
			{
				cd += 365;
				if (cd - dd > 1)
				{
					if (cd - dd <= 7)
					{
						cout << b << '/' << dday[2] + 1 << " IS " << cd - dd << " DAYS AFTER";
					}
					else
					{
						cout << "OUT OF RANGE";
					}
				}
				else
				{
					if (cd - dd <= 7)
					{
						cout << b << '/' << dday[2] + 1 << " IS " << cd - dd << " DAY AFTER";
					}
					else
					{
						cout << "OUT OF RANGE";
					}
				}
			}
		}

		cout << '\n';
	}


	return 0;
}
