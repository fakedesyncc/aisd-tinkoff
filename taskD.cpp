#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double C) {
    return x * x + sqrt(x + 1) - C;
}

double find_x(double C) {
    double left = 0.0;
    double right = C;
    double mid;

    double epsilon = 1e-7;

    while (right - left > epsilon) {
        mid = (left + right) / 2.0;
        if (f(mid, C) < 0) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return (left + right) / 2.0;
}

int main() {
    double C;
    cin >> C;

    double x = find_x(C);
    cout << defaultfloat << setprecision(15) << x << endl;

    return 0;
}