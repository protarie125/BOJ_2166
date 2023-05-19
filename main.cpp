#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>
#include <iomanip>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

int n;
vector<double> xs;
vector<double> ys;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	xs = vector<double>(n);
	ys = vector<double>(n);
	for (const auto& i : ranges::iota_view{ 0, n }) {
		cin >> xs[i] >> ys[i];
	}

	auto ans = double{ 0 };
	for (const auto& i : ranges::iota_view{ 1, n - 1 }) {
		const auto j = i + 1;
		const auto dx0 = xs[i] - xs[0];
		const auto dy0 = ys[i] - ys[0];
		const auto dx1 = xs[j] - xs[0];
		const auto dy1 = ys[j] - ys[0];
		ans += (dx0 * dy1 - dx1 * dy0) / 2;
	}
	ans = abs(ans);

	cout << fixed << setprecision(1) << round(ans * 10) / 10;

	return 0;
}