#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;
// TODO: Define Point struct if not given
// struct Point {
// };

struct Point {
    double x;
    double y;
};


string format_number(double v) {
   
    double rounded = round(v * 1e6) / 1e6;  
    if (fabs(rounded - round(rounded)) < 1e-6) {
        // print as integer
        return to_string((long long)llround(rounded));
    } else {
       
        ostringstream oss;
        oss << rounded;
        return oss.str();
    }
}

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << format_number(x_before)
         << ", y=" << format_number(y_before) << ")\n";

    cout << "After rotation (θ=" << fixed << setprecision(4) << theta << " rad): "
         << "(x=" << format_number(x_after)
         << ", y=" << format_number(y_after) << ")\n";
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

    Point point, pivot;
    double theta;

    input >> point.x >> point.y >> theta >> pivot.x >> pivot.y;

    // Compute rotated coordinates
    double dx = point.x - pivot.x;
    double dy = point.y - pivot.y;

    double x_after = pivot.x + dx * cos(theta) - dy * sin(theta);
    double y_after = pivot.y + dx * sin(theta) + dy * cos(theta);

   
    if (fabs(x_after) < 1e-6) x_after = 0.0;
    if (fabs(y_after) < 1e-6) y_after = 0.0;

    print_point_rotation(point.x, point.y, theta, x_after, y_after);
// TODO: Declare point, pivot, and angle variables


    // TODO: Read input from file: x, y, theta, px, py


    // TODO: Compute rotated coordinates around pivot


    // TODO: Print rotated point
   
   
   
   
    return 0;
}
	
