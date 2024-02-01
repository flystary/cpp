#include <iostream>
#include <vector>
#include <numeric>


double computeVariance(const std::vector<double>& data)
{
    int n = data.size();

    if (n <= 1) return 0.0;

    double sum  = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / n;



    double variance = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = data[i] - mean;
        variance += diff * diff;
    }
    variance /= n;

    return variance;
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    double variance = computeVariance(data);

    std::cout << "方差: " << variance << std::endl;
    return 0;
}
