#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int r, c;
vector<string> v;

bool solve(int mid)
{
	vector<string> tmp;
	tmp.resize(c);

	for (int i = 0; i < c; i++)
	{
		tmp[i] = v[i].substr(0, mid);
	}

	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < c-1; i++)
	{
		if (tmp[i] == tmp[i + 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	v.resize(c);
	for (int j = 0; j < c; j++) v[j].resize(r);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> v[j][r - i - 1];
		}
	}

	int st = 0;
	int en = r*2;

	int ans = 0;
	// 얼마나 짧게 잘라도 중복이 안되는가? 를 찾아야한다.
	while(st+1 < en)
	{
		int mid = (st + en) / 2; 
		if (solve(mid))
		{
			en = mid;
			ans = mid;
		}
		else
		{
			st = mid;
		}
	}

	cout << r- ans;

	return 0;
}