#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi v(26);
	for (int i = 0; i < n; i++)
	{
		string n;
		cin >> n;
		v[n[0] - 'a']++;
	}

	string ans = "";
	for (int i = 0; i < 26; i++)
	{
		if (v[i] >= 5)
		{
			ans += i + 'a';
		}
	}

	cout << (ans.empty() ? "PREDAJA" : ans);


	return 0;
}