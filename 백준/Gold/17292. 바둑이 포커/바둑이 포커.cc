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

int htod(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else
	{
		return c - 'a' + 10;
	}
}

int check(string s)
{
	int num1 = htod(s[0]);
	int num2 = htod(s[2]);
	int gap = abs(num1 - num2);
	if (gap == 1 || gap == 14)// 1tof
	{
		return 0;
	}
	else if (num1 == num2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

bool compare(string a, string b)
{
	int a1 = htod(a[0]);
	int a2 = htod(a[2]);
	char ac = a[3];
	if (a1 > a2)
	{
		ac = a[1];
		swap(a1, a2);
	}

	int b1 = htod(b[0]);
	int b2 = htod(b[2]);
	char bc = b[3];

	if (b1 > b2)
	{
		bc = b[1];
		swap(b1, b2);
	}

	if ((a[1] == a[3]) == (b[1] == b[3]))
	{
		if (a2 == b2)
		{
			if (a1 == b1)
			{
				return ac < bc;
			}
			return a1 > b1;
		}
		return a2 > b2;
	}
	return (a[1] == a[3]) > (b[1] == b[3]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	istringstream iss;
	iss.str(s);

	vector<string> cards;
	string tmp;
	while (getline(iss, tmp, ','))
	{
		cards.push_back(tmp);
	}

	vector<string> v;
	for (int i = 0; i < cards.size(); i++)
	{
		for (int j = i + 1; j < cards.size(); j++)
		{
			v.push_back(cards[i] + cards[j]);
		}
	}

	sort(v.begin(), v.end(),
		[](auto& a, auto& b)
		{
			int a1 = check(a);
			int b1 = check(b);
			if (a1 == b1)
			{
				return compare(a, b);
			}
			return a1 < b1;
		});

	for (auto str : v)
	{
		cout << str << '\n';
	}

	return 0;
}