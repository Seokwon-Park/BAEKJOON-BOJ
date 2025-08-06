#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

string nums[31] =
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"quarter",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
	"twenty",
	"twenty one",
	"twenty two",
	"twenty three",
	"twenty four",
	"twenty five",
	"twenty six",
	"twenty seven",
	"twenty eight",
	"twenty nine",
	"half"
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, m;
	cin >> h >> m;

	if (m == 0)
	{
		cout << nums[h] << " o' clock";
	}
	else if (m == 30 || m == 15)
	{
		cout << nums[m] << " past " << nums[h];
	}
	else if (m == 45)
	{
		cout << nums[60 - m] << " to " << nums[h % 12 + 1];
	}
	else if (m >= 1 && m < 30)
	{
		cout << nums[m] << (m == 1 ? " minute past " : " minutes past ") << nums[h];
	}
	else if (m > 30)
	{
		int to = 60 - m;
		cout << nums[to] << (to == 1 ? " minute to " : " minutes to ") << nums[h % 12 + 1];
	}


	return 0;
}