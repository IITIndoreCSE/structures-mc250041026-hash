#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Rectangle {
    int index;
    double width;
    double height;
    double thickness;
    double density;
    char material[100];  // Allocate space for material
};

void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    cout << "Plate[" << index << "]: "
         << "width=" << width << ", "
         << "height=" << height << ", "
         << "density=" << density << ", "
         << "mass=" << mass << ", "
         << "material=" << material << "\n";
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

    int num_plates;
    input >> num_plates;
    input.ignore(); 

    const int MAX_PLATES = 10;
    Rectangle plates[MAX_PLATES];

    for (int i = 0; i < num_plates; i++) {
        input >> plates[i].width;
        input.ignore();
        input >> plates[i].height;
        input.ignore();
        input >> plates[i].thickness;  
        input >> plates[i].density;
        input.ignore();
        input.getline(plates[i].material, 100);

        
        double mass = plates[i].width * plates[i].height * plates[i].thickness * plates[i].density;

        print_plate(i, plates[i].width, plates[i].height, plates[i].density, mass, plates[i].material);
    }

    return 0;
}
