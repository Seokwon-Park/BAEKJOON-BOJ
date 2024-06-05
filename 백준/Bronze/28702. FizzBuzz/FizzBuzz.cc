#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string> fb(3);

	int nxt = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> fb[i];
		if (fb[i] != "Fizz" && fb[i] != "Buzz" && fb[i] != "FizzBuzz")
		{
			int tmp = stoi(fb[i]);
			nxt = tmp + (3 - i);
		}
	}

	if (nxt % 5 == 0 && nxt % 3 == 0)
		cout << "FizzBuzz";
	else if (nxt % 3 == 0)
		cout << "Fizz";
	else if (nxt % 5 == 0)
		cout << "Buzz";
	else
		cout << nxt;

	return 0;
}