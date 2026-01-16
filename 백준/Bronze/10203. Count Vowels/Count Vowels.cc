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
using hashmap = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int vowel = 0;
		for (auto c : s)
		{
			if (c == 'a' ||
				c == 'e' ||
				c == 'i' ||
				c == 'o' ||
				c == 'u')
				vowel++;
		}
		cout << "The number of vowels in " << s << " is " << vowel << ".\n";
	}

	return 0;
}