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
	cin >> n;
	vector<int> hotel(370);
	vector<int> space(370);
	vector<int> tab(370);
	vector<int> pf(370);
	vector<int> pfs(370);
	vector<int> pft(370);

	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	for (int i = 0; i < n; i++)
	{
		char c;
		int s, e;
		cin >> c >> s >> e;
		hotel[s]++;
		hotel[e + 1]--;
		if (c == 'T')
		{
			tab[s]++;
			tab[e + 1]--;
		}
		else
		{
			space[s]++;
			space[e + 1]--;
		}
		E = max(E, e - s + 1);
	}

	for (int i = 1; i <= 366; i++)
	{
		pf[i] = pf[i - 1] + hotel[i];
		pfs[i] = pfs[i - 1] + space[i];
		pft[i] = pft[i - 1] + tab[i];
		if (pf[i] > 0)
		{
			A++;
		}
		if ((pfs[i] > 0 && pft[i] > 0) && pfs[i] == pft[i])
		{
			C++;
			D = max(D, pf[i]);
		}
		B = max(B, pf[i]);
	}

	cout << A << '\n' << B << '\n' << C << '\n' << D << '\n' << E;

	return 0;
}