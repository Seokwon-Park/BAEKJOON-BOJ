#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

map <string, int> m;
tuple<int, int, double, double, double> v[6];
int score[4];
double ans[4];

void func(int k, double t)
{
	if (t == 0) return;
	if (k == 6)
	{
		vector<pair<int, int>> tmp(4);
		for (int i = 0; i < 4; i++)
		{
			tmp[i] = { score[i], i };
		}
		sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());

		if (tmp[1].first != tmp[2].first)
		{
			ans[tmp[0].second] += t;
			ans[tmp[1].second] += t;
		}
		else if (tmp[0].first == tmp[1].first && tmp[2].first == tmp[3].first)
		{
			ans[tmp[0].second] += t / 2;
			ans[tmp[1].second] += t / 2;
			ans[tmp[2].second] += t / 2;
			ans[tmp[3].second] += t / 2;
		}
		else if (tmp[0].first == tmp[1].first)
		{
			ans[tmp[0].second] += t * 2 / 3;
			ans[tmp[1].second] += t * 2 / 3;
			ans[tmp[2].second] += t * 2 / 3;
		}
		else if (tmp[2].first == tmp[3].first)
		{
			ans[tmp[0].second] += t;
			ans[tmp[1].second] += t / 3;
			ans[tmp[2].second] += t / 3;
			ans[tmp[3].second] += t / 3;
		}
		else
		{
			ans[tmp[0].second] += t;
			ans[tmp[1].second] += t/2;
			ans[tmp[2].second] += t/2;
		}
		return;
	}

	int a, b;
	double w, d, l;
	tie(a, b, w, d, l) = v[k];
	score[a] += 3;
	func(k + 1, t * w);
	score[a] -= 3;

	score[a]++;
	score[b]++;
	func(k + 1, t * d);
	score[a]--;
	score[b]--;

	score[b] += 3;
	func(k + 1, t * l);
	score[b] -= 3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
	{
		string team;
		cin >> team;
		m[team] = i;
	}

	for (int i = 0; i < 6; i++)
	{
		string a, b;
		cin >> a >> b;
		int anum = m[a];
		int bnum = m[b];
		double w, d, l;
		cin >> w >> d >> l;
		v[i] = tie(anum, bnum, w, d, l);
	}

	func(0, 1.0);

	for (int i = 0; i < 4; i++)
	{
		cout << fixed << setprecision(6);
		cout << ans[i] << '\n';
	}

	return 0;
}