
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define the Sensor struct with id, temperature, voltage, and status
struct Sensor {
    int id;
    double temperature;
    double voltage;
    char status[20]; // Use a character array for status (string)
};

// Function to print details of a sensor
void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    cout << "Sensor[" << index << "]: "
         << "id=" << id << ", "
         << "temperature=" << temperature << ", "
         << "voltage=" << voltage << ", "
         << "status=" << status << "\n";
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

    int num_sensors;
    input >> num_sensors;

    const int MAX_SENSORS = 10;

    // Create an array of Sensor structs
    Sensor sensors[MAX_SENSORS];

    // Read sensor data from the input file
    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id;
        input >> sensors[i].temperature;
        input >> sensors[i].voltage;
        input >> sensors[i].status;
    }

    // Pointer to iterate through the array and print sensor data
    Sensor* sensor_ptr = sensors;

    for (int i = 0; i < num_sensors; i++) {
        // Use the pointer to access the members of each sensor
        print_sensor(i, sensor_ptr->id, sensor_ptr->temperature, sensor_ptr->voltage, sensor_ptr->status);
        sensor_ptr++; // Move the pointer to the next sensor
    }

    return 0;
}
