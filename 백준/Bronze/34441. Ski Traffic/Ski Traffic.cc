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

	string n;
	getline(cin, n);
	string t;
	cin >> t;
	int colon = t.find(':');
	int h = stoi(t.substr(0, colon));
	int m = stoi(t.substr(colon + 1));

	int mul = 1;
	string d;
	cin >> d;
	if (d == "sat" || d == "sun") mul *= 2;
	bool i70;
	cin >> i70;
	if (i70) mul *= 2;
	bool fr;
	cin >> fr;
	if (fr) mul *= 3;
	bool holiday;
	cin >> holiday;
	if (holiday) mul *= 3;

	h *= mul;
	m *= mul;

	cout << h + m / 60 << ':' << setw(2) << setfill('0')<< m % 60;

	return 0;
}
