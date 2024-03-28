#include<iostream>
#include<unordered_map>
#include<climits>
#include<cmath>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		double a1, p1, r1, p2;
		cin >> a1 >> p1 >> r1 >> p2;
		double piece = a1 / p1;
		double whole = r1 * r1 * acos(-1) / p2;
		if (piece > whole)
			cout << "Slice of pizza\n";
		else
			cout << "Whole pizza\n";
	
	}

	return 0;
}