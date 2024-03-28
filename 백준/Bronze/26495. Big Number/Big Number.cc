#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string digits[10][5];
	digits[0][0] = "0000";
	digits[0][1] = "0  0";
	digits[0][2] = "0  0";
	digits[0][3] = "0  0";
	digits[0][4] = "0000";
	digits[1][0] = "   1";
	digits[1][1] = "   1";
	digits[1][2] = "   1";
	digits[1][3] = "   1";
	digits[1][4] = "   1";
	digits[2][0] = "2222";
	digits[2][1] = "   2";
	digits[2][2] = "2222";
	digits[2][3] = "2";
	digits[2][4] = "2222";
	digits[3][0] = "3333";
	digits[3][1] = "   3";
	digits[3][2] = "3333";
	digits[3][3] = "   3";
	digits[3][4] = "3333";
	digits[4][0] = "4  4";
	digits[4][1] = "4  4";
	digits[4][2] = "4444";
	digits[4][3] = "   4";
	digits[4][4] = "   4";
	digits[5][0] = "5555";
	digits[5][1] = "5";
	digits[5][2] = "5555";
	digits[5][3] = "   5";
	digits[5][4] = "5555";
	digits[6][0] = "6666";
	digits[6][1] = "6";
	digits[6][2] = "6666";
	digits[6][3] = "6  6";
	digits[6][4] = "6666";
	digits[7][0] = "7777";
	digits[7][1] = "   7";
	digits[7][2] = "   7";
	digits[7][3] = "   7";
	digits[7][4] = "   7";
	digits[8][0] = "8888";
	digits[8][1] = "8  8";
	digits[8][2] = "8888";
	digits[8][3] = "8  8";
	digits[8][4] = "8888";
	digits[9][0] = "9999";
	digits[9][1] = "9  9";
	digits[9][2] = "9999";
	digits[9][3] = "   9";
	digits[9][4] = "   9";

	string n;
	cin >> n;
	for (auto c : n)
	{
		int ix = c - '0';
		for (int j = 0; j < 5; j++)
		{
			cout << digits[ix][j] << '\n';
		}
		cout << '\n';
	}


	return 0;
}