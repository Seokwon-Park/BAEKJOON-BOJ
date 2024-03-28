#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string heart[9];
	heart[0] = " @@@   @@@ ";
	heart[1] = "@   @ @   @";
	heart[2] = "@    @    @";
	heart[3] = "@         @";
	heart[4] = " @       @ ";
	heart[5] = "  @     @  ";
	heart[6] = "   @   @   ";
	heart[7] = "    @ @    ";
	heart[8] = "     @     ";

	int n;
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << heart[i] << ' ';
		}
		cout << '\n';
	}


	return 0;
}