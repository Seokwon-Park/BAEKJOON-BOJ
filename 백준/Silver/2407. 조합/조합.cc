#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

class BigInteger
{
public:

	BigInteger() { value.push_back(0); }
	BigInteger(string s)
	{
		int blockcnt = s.size() / 9 + (s.size() % 9 != 0);
		s = string(blockcnt * 9 - s.size(), '0') + s;
		for (int i = 0; i < s.size(); i += 9)
		{
			value.push_back(stoi(s.substr(s.size() - 9 * (i + 1), 9)));
		}
	}

	BigInteger(ll n)
	{
		value.push_back(n % base);
		if (n >= base)
		{
			value.push_back(n / base);
		}
	}

	BigInteger operator+(const BigInteger& other) const
	{
		BigInteger result;
		result.value.clear();

		long long carry = 0;
		int i = 0, j = 0;

		while (i < this->value.size() || j < other.value.size() || carry)
		{
			long long sum = carry;
			if (i < this->value.size())
			{
				sum += this->value[i++];
			}
			if (j < other.value.size())
			{
				sum += other.value[j++];
			}
			result.value.push_back(sum % base);
			carry = sum / base;
		}
		return result;
	}

	BigInteger operator-(const BigInteger& other) const
	{
		if (*this < other) {
			return BigInteger();
		}

		BigInteger result;
		result.value.clear();
		ll borrow = 0;

		for (int i = 0; i < value.size(); i++)
		{
			ll diff = value[i] - borrow;
			borrow = 0;

			if (i < other.value.size())
			{
				diff -= other.value[i];
			}

			if (diff < 0) {
				diff += base;
				borrow = 1;
			}
			result.value.push_back(diff);
		}

		result.RemoveLeadingZero();

		return result;
	}


	BigInteger operator*(const BigInteger& other) const
	{
		BigInteger result;
		result.value.clear();
		result.value.resize(value.size() + other.value.size(), 0);
		for (int i = 0; i < value.size(); i++)
		{
			for (int j = 0; j < other.value.size(); j++)
			{
				result.value[i + j] += value[i] * other.value[j];
			}
		}

		for (int i = 0; i < result.value.size() - 1; i++)
		{
			result.value[i + 1] += result.value[i] / base;
			result.value[i] %= base;
		}

		result.RemoveLeadingZero();

		return result;
	}

	BigInteger operator/(const BigInteger& other) const
	{
		if (other.value.size() == 1 && other.value[0] == 0) {
			throw runtime_error("Division by zero");
		}
		return divide(other).first;
	}

	BigInteger operator%(const BigInteger& other) const
	{
		if (other.value.size() == 1 && other.value[0] == 0) {
			throw runtime_error("Division by zero");
		}
		return divide(other).second;
	}


	BigInteger operator=(const BigInteger& other)
	{
		value = other.value;

		return *this;
	}

	bool operator<(const BigInteger& other) const
	{
		if (value.size() == other.value.size())
		{
			for (int i = other.value.size() - 1; i >= 0; i--)
			{
				if (value[i] == other.value[i])continue;
				return value[i] < other.value[i];
			}
		}
		return value.size() < other.value.size();
	}

	bool operator==(const BigInteger& other) const { return value == other.value; }
	bool operator<=(const BigInteger& other) const { return *this < other || other == *this; }
	bool operator>=(const BigInteger& other) const { return other < *this || other == *this; }
	bool operator>(const BigInteger& other) const { return other < *this; }

	string ToString() const
	{
		if (value.empty() || (value.size() == 1 && value[0] == 0))
		{
			return "0";
		}

		stringstream ss;
		ss << value.back();

		for (int i = value.size() - 2; i >= 0; i--)
		{
			ss << setw(9) << setfill('0') << value[i];
		}
		return ss.str();
	}

private:
	void RemoveLeadingZero()
	{
		while (value.size() > 1 && value.back() == 0)
		{
			value.pop_back();
		}
	}

	pair<BigInteger, BigInteger> divide(const BigInteger& other) const
	{
		// A < B 이면 몫은 0, 나머지는 A
		if (*this < other) {
			return { BigInteger(), *this };
		}

		BigInteger quotient;
		BigInteger current;
		quotient.value.clear();

		for (int i = this->value.size() - 1; i >= 0; --i)
		{
			current.value.insert(current.value.begin(), 0);
			current.value[0] = this->value[i];
			current.RemoveLeadingZero();

			long long digit = 0;
			if (current >= other) {
				long long low = 0, high = base;
				while (low + 1 < high)
				{
					long long mid = (low + high) / 2;
					if (other * BigInteger(to_string(mid)) <= current)
					{
						low = mid;
					}
					else
					{
						high = mid;
					}
				}
				digit = low;
			}

			quotient.value.insert(quotient.value.begin(), digit);
			if (digit > 0) {
				current = current - (other * BigInteger(to_string(digit)));
			}
		}

		quotient.RemoveLeadingZero();

		return { quotient, current };
	}

	vector<ll> value;
	const ll base = 1e9;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	BigInteger a(1);
	BigInteger b(1);
	for (int i = 0; i < m; i++)
	{
		BigInteger x(n - i);
		BigInteger y(i + 1);
		a = a * x;
		b = b * y;
	}

	cout << (a / b).ToString();

	return 0;
}