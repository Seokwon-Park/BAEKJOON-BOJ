#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool equals(string a, string b)
{
	return a == b;
}
bool equalsIgnoreCase(string a, string b)
{
	if(a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (isalpha(a[i]))
		{
			a[i] = tolower(a[i]);
		}
		if (isalpha(b[i]))
		{
			b[i] = tolower(b[i]);
		}
	}
	return a == b;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	if (a == "null")
	{
		cout << "NullPointerException\n";
		cout << "NullPointerException\n";
	}
	else if (b == "null")
	{
		cout << boolalpha << equals(a, "") << '\n';
		cout << boolalpha << equalsIgnoreCase(a, "") << '\n';
	}
	else
	{
		cout << boolalpha << equals(a, b) << '\n';
		cout << boolalpha << equalsIgnoreCase(a, b) << '\n';
	}

	return 0;
}



