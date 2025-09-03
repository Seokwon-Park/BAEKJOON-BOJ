#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	double s, a, t, m;

	cin >> n;

	double score = 0.0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> a >> t >> m;
		score += s * (1.0 + 1.0 / a) * (1.0 + m / t) / 4.0;
	}

	int p;
	cin >> p;
	vector<double> v(p);
	for (int i = 0; i < p; i++)
	{
		cin >> v[i];
	}
	v.push_back(score);

	sort(v.begin(), v.end(), greater<double>());

	int rank = find(v.begin(), v.end(), score) - v.begin() + 1;

	cout << fixed << setprecision(2);
	if (rank <= floor((p + 1) * 0.15))
	{
		cout << "The total score of Younghoon \"The God\" is " << score << ".";

	}
	else
	{
		cout << "The total score of Younghoon is " << score << ".";
	}

	return 0;
}