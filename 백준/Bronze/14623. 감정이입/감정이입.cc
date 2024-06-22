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

	string a, b;
	cin >> a >> b;
	
	int sz = a.size() + b.size();
	vector<int> res(sz);
	for(int i = 0; i< a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			int apos = a.size() - 1 - i;
			int bpos = b.size() - 1 - j;
			int aa = a[apos] - '0';
			int bb = b[bpos] - '0';
			int tmp = aa & bb;
			res[i + j] += tmp;
			if (res[i + j] >= 2)
			{
				res[i + j + 1] += res[i+j]/2;
				res[i + j] %= 2;
			}
		}
	}
	while (res.back() == 0) res.pop_back();
	for (int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i];
	}


	return 0;
}