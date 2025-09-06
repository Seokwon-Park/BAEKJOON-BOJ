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
	
	string s;
	cin >> s;
	istringstream iss;
	iss.str(s);
	vector<int> v;
	string tmp;
	while (getline(iss, tmp, '-'))
	{
		v.push_back(stoi(tmp));
	}
	int m = v[1];
	int d = v[2];

	switch (m)
	{
	case 1:
	{
		if (d < 20) cout << "Capricorn";
		else cout << "Aquarius";
		break;
	}
	case 2:
	{
		if (d < 19) cout << "Aquarius";
		else cout << "Pisces";
		break;
	}
	case 3:
	{
		if (d < 21) cout << "Pisces";
		else cout << "Aries";
		break;
	}
	case 4:
	{
		if (d < 20) cout << "Aries";
		else cout << "Taurus";
		break;
	}
	case 5:
	{
		if (d < 21) cout << "Taurus";
		else cout << "Gemini";
		break;
	}
	case 6:
	{
		if (d < 21) cout << "Gemini";
		else cout << "Cancer";
		break;
	}
	case 7:
	{
		if (d < 23) cout << "Cancer";
		else cout << "Leo";
		break;
	}
	case 8:
	{
		if (d < 23) cout << "Leo";
		else cout << "Virgo";
		break;
	}
	case 9:
	{
		if (d < 23) cout << "Virgo";
		else cout << "Libra";
		break;
	}
	case 10:
	{
		if (d < 23) cout << "Libra";
		else cout << "Scorpio";
		break;
	}
	case 11:
	{
		if (d < 23) cout << "Scorpio";
		else cout << "Sagittarius";
		break;
	}
	case 12:
	{
		if (d < 22) cout << "Sagittarius";
		else cout << "Capricorn";
		break;
	}
	}


	return 0;
}