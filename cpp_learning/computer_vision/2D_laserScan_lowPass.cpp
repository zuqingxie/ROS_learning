#include <iostream>
#include <vector>

class LowpassFilter {
public:
    LowpassFilter(double alpha) : alpha(alpha), initialized(false) {}

    double filter(double input) {
        if (!initialized) {
            prevOutput = input;
            initialized = true;
        }

        double output = alpha * input + (1 - alpha) * prevOutput;
        prevOutput = output;

        return output;
    }

private:
    double alpha;        // Smoothing factor (0 < alpha < 1)
    double prevOutput;   // Previous filtered output
    bool initialized;    // Flag to check if filter has been initialized
};

int main() {
    // Define your laser scan data as a vector of doubles
    std::vector<double> laserScanData = {1.0, 2.0, 3.0, 4.0, 5.0,9.0,5.0};

    // Create a lowpass filter with a smoothing factor (alpha)
    LowpassFilter filter(0.2); // You can adjust the smoothing factor as needed

    // Apply the filter to the laser scan data
    std::vector<double> filteredData;
    for (double dataPoint : laserScanData) {
        double filteredValue = filter.filter(dataPoint);
        filteredData.push_back(filteredValue);
    }

    // Print the filtered data
    std::cout << "Filtered Laser Scan Data:" << std::endl;
    for (double dataPoint : filteredData) {
        std::cout << dataPoint << " ";
    }
    std::cout << std::endl;

    return 0;
}
