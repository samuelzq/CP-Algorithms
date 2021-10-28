#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long b, p, m;

	while (cin >> b) {
		cin >> p >> m;
		long long s, a;
		s = 1;
		a = b % m;
		while (p) {
			if (p & 1)
				s = s * a % m;
			a = a * a % m;
			p >>= 1;
		}
		cout << s << '\n';
	}
	return 0;
}
