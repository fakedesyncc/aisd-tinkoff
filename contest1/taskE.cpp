#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double polynomial(double x, double a, double b, double c, double d) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double findRoot(double a, double b, double c, double d, double tolerance) {
    double left = -1000;
    double right = 1000;
    double root = 0;


    while (polynomial(left, a, b, c, d) * polynomial(right, a, b, c, d) > 0) {
        left -= 1000;
        right += 1000;
    }


    while (abs(right - left) > tolerance) {
        double mid = (left + right) / 2;
        if (polynomial(left, a, b, c, d) * polynomial(mid, a, b, c, d) > 0) {
            left = mid;
        } else {
            right = mid;
        }
        root = (left + right) / 2;
    }

    return root;
}

int main() {
    double a, b, c, d;
    double tolerance = 0.000001;

    cin >> a >> b >> c >> d;

    double root = findRoot(a, b, c, d, tolerance);

    if (isnan(root)) {
        if (abs(root - 1.0) < 1e-5) {
            root = 1.0;
        }
    }

    cout << fixed << setprecision(10) << root << endl;

    return 0;
}