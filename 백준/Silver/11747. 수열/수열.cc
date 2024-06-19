#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	bool zero = false;
	for(int i = 0; i< n; i++)
	{
		cin >> v[i];
		if (v[i] == 0) zero = true;
	}

	if (!zero)
	{
		cout << 0;
		return 0;
	}
	int find = 0;
	int numsz = 1;
	int pow = 10;
	while (1)
	{
		set<int> s;
		for (int i = 0; i < n-numsz+1; i++)
		{
			int res = 0;
			for (int j = 0; j < numsz; j++)
			{
				res = res * 10 + v[i + j];
			}
			s.insert(res);
		}
		for (int i = pow / 10; i < pow; i++)
		{
			if (s.find(i) == s.end())
			{
				cout << i;
				return 0;
			}
		}
		numsz++;
		pow *= 10;
	}





	return 0;
}