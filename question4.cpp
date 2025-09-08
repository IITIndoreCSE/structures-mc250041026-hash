#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// TODO: Define TaylorTerm struct
// struct TaylorTerm {
// };

struct TaylorTerm {
    int order;
    int coeff; // ±1
    double value; // rounded value (to 6 decimal places)
};

double factorial(int n) {
    double f = 1.0;
    for (int i = 2; i <= n; ++i) f *= i;
    return f;
}

// Format a double rounded to 6 decimal places, trimming trailing zeros
string format_term_value(double v) {
    // Round to 6 decimal places
    double rounded = std::round(v * 1e6) / 1e6;

    // Avoid negative zero
    if (fabs(rounded) < 0.5e-12) rounded = 0.0;

    // If zero after rounding, print "0"
    if (rounded == 0.0) return "0";

    ostringstream oss;
    oss << fixed << setprecision(6) << rounded;
    string s = oss.str();

    // Trim trailing zeros and possible trailing decimal point
    if (s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    return s;
}

void print_taylor_term(int index, int order, int coeff, const string &value_str) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value_str << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << fixed << setprecision(6) << approximation << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    double x;
    int terms;
    input >> x >> terms;
   
   // TODO: Create an array of TaylorTerm
    // TaylorTerm series[terms];
    // Create an array of TaylorTerm to store the terms
    vector<TaylorTerm> series;
    series.reserve(terms);

    double approximation = 0.0;
   
    // TODO: Compute each Taylor term and store in array
    // for (int k = 0; k < terms; k++) {
    // }
    // Compute each Taylor term and store it in the array
   
    for (int k = 0; k < terms; ++k) {
        int order = 2 * k;
        int coeff = (k % 2 == 0) ? 1 : -1;

        double raw_value = coeff * pow(x, order) / factorial(order);
        // Round and format value (and use the rounded value for the approximation)
        double rounded_value = std::round(raw_value * 1e6) / 1e6;
        if (fabs(rounded_value) < 0.5e-12) rounded_value = 0.0;

        series.push_back({order, coeff, rounded_value});
        approximation += rounded_value;

        string vs = format_term_value(rounded_value);
        print_taylor_term(k, order, coeff, vs);
    }
      // TODO: Print final approximation
        // Store in the series array
    print_taylor_result("cos", x, terms, approximation);

    return 0;
}
