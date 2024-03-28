#include<iostream>
#include<unordered_map>
#include<climits>
#include<cmath>
#include<vector>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (char& c : s)
	{
		if (c == 'a')
			c = '4';
		else if (c == 'e')
			c = '3';
		else if (c == 'i')
			c = '1';
		else if (c == 'o')
			c = '0';
		else if (c == 's')
			c = '5';
	}
	cout << s;

	return 0;
}