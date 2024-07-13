#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		int m;
		cin >> name >> m;
		cout << name << ' ';
		if (m >= 97)
			cout << "A+";
		else if (m >= 90)
			cout << "A";
		else if (m >= 87)
			cout << "B+";
		else if (m >= 80)
			cout << "B";
		else if (m >= 77)
			cout << "C+";
		else if (m >= 70)
			cout << "C";
		else if (m >= 67)
			cout << "D+";
		else if (m >= 60)
			cout << "D";
		else
			cout << "F";
		cout << '\n';
	}

	return 0;
}