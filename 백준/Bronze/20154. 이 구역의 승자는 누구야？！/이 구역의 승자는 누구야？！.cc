#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int a[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> v;
	for (auto c : s)
	{
		v.push_back(a[c - 'A']);
	}

	while (v.size() > 1)
	{
		vector<int> nv;
		for (int i = 0; i < v.size(); i += 2)
		{
			if (i + 1 < v.size())
			{
				nv.push_back((v[i] + v[i + 1]) % 10);
			}
			else
			{
				nv.push_back(v[i]%10);
			}
		}
		v.swap(nv);
	}
	if (v[0] % 2)
		cout << "I'm a winner!";
	else
		cout << "You're the winner?";

	return 0;
}