#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int num;

string print(int n)
{
	string ret = "";
	string bottle = (n == 0 ? "no more" : to_string(n));
	string top = bottle + (n == 1 ? " bottle" : " bottles") + " of beer on the wall, " + bottle + (n == 1 ? " bottle" : " bottles") + " of beer.\n";
	top[0] = toupper(top[0]);
	string bot = "";
	if (n == 0)
	{
		bot = "Go to the store and buy some more, " + to_string(num) + (num == 1 ? " bottle" : " bottles") + " of beer on the wall.";
	}
	else
	{
		bot = "Take one down and pass it around, " + (n - 1 == 0 ? "no more" : to_string(n - 1)) + (string)(n - 1 == 1 ? " bottle" : " bottles") + " of beer on the wall.\n\n";
	}
	ret = top + bot;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> num;

	for (int i = 0; i <= num; i++)
	{
		cout << print(num - i);
	}




	return 0;
}