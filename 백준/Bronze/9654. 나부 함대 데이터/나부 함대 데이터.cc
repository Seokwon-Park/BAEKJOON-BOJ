#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name[6] = { "SHIP NAME", "N2 Bomber", "J-Type 327", "NX Cruiser" , "N1 Starfighter" , "Royal Cruiser" };
	string clss[6] = { "CLASS", "Heavy Fighter", "Light Combat", "Medium Fighter" , "Medium Fighter" , "Light Combat" };
	string deploy[6] = { "DEPLOYMENT", "Limited", "Unlimited", "Limited" , "Unlimited" , "Limited" };
	string inserv[6] = { "IN SERVICE", "21", "1", "18", "25" , "4" };

	for (int i = 0; i < 6; i++)
	{
		cout << left << setw(15) << name[i] << setw(15) << clss[i] << setw(11) << deploy[i] << setw(10) << inserv[i] << '\n';
	}

	return 0;
}