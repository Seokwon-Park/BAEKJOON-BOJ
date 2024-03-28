#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string n;
	cin >> n;

	int b = 0, c = 0;
	for (char ch : n)
	{
		if (ch == 'B')
			b++;
		else
			c++;

	}

	cout << b / 2 + c / 2;

	return 0;
}