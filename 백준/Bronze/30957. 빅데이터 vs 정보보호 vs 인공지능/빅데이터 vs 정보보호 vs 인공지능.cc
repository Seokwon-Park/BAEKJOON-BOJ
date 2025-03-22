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
	string s;
	cin >> s;
	vector<int> v(3);
	for (auto c : s)
	{
		switch (c)
		{
		case 'B':
			v[0]++;
			break;
		case 'S':
			v[1]++;
			break;
		case'A':
			v[2]++;
			break;
		default:
			break;
		}
	}

	string bsa = "BSA";
	auto mx = max_element(v.begin(), v.end());
	int res = count(v.begin(), v.end(), *mx);
	if (res == 3)
	{
		cout << "SCU";
	}
	else if(res == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			if (v[i] == *mx)
				cout << bsa[i];
		}
	}
	else
	{
		cout << bsa[mx - v.begin()];
	}

	return 0;
}