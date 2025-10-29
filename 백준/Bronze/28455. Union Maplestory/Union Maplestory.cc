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
	vector<int> v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	sort(v.begin(), v.end(), greater<int>());

	int lv = 0;
	int un = 0;
	for (int i = 0; i < min(42, n); i++)
	{
		lv += v[i];
		if (v[i] >= 250) un += 5;
		else if (v[i] >= 200) un += 4;
		else if (v[i] >= 140) un += 3;
		else if (v[i] >= 100) un += 2;
		else if(v[i] >= 60)un += 1;
	}
	
	cout << lv << ' ' << un;

	return 0;
}