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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int d, m;
	cin >> d >> m;
	int cont = 0;
	map<char, int> v;
	v['H'] = 0;
	v['Y'] = 0;
	v['U'] = 0;
	int energy = 0;
	for (auto c : s)
	{
		if (c != 'H' && c != 'Y' && c != 'U')
		{
			cont++;
		}
		else
		{
			energy += min(d * cont, d + m);
			cont = 0;
			v[c]++;
		}
	}
	energy += min(d * cont, d + m);
	if (energy == 0)
	{
		cout << "Nalmeok\n";
	}
	else
	{
		cout << energy << '\n';
	}

	auto [a, b] = *min_element(v.begin(), v.end(), [](auto a, auto b)
		{
			return a.second < b.second;
		});
	if (b == 0)
	{
		cout << "I love HanYang University";
	}
	else
	{
		cout << b;
	}

	return 0;
}