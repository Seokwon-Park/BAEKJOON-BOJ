#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while (getline(cin, str))
	{
		int a = 0;
		int A = 0;
		int num = 0;
		int sp = 0;

		for(char c: str)
		{
			if (c >= 'a' && c <= 'z')
				a++;
			else if (c >= 'A' && c <= 'Z')
				A++;
			else if (c >= '0' && c <= '9')
				num++;
			else
				sp++;
		}

		cout << a << ' ' << A << ' ' << num << ' ' << sp << '\n';
	}

	return 0;
}