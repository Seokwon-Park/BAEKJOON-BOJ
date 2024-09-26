#include<bits/stdc++.h>

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
	while (getline(cin , a) && getline(cin, b))
	{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int n = a.size() + b.size();
		string res(n, ' ');
		auto itr = set_intersection(a.begin(), a.end(), b.begin(), b.end(), res.begin());
		res.resize(itr - res.begin());

		for (auto c : res)
			cout << c;
		cout << '\n';
	}

	return 0;
}

