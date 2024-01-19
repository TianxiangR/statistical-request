#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <vector>
#include <string>

class Statistics
{
private:
    std::vector<double> m_data;
    int m_max_bins;
    std::string doubleToTwoDecimalPlaces(const double &value) const;

public:
    Statistics(const int &bins = 10);

    double getMean() const;

    double getStandardDeviation() const;

    std::string getNormalizedHistogram() const;

    void addData(const double &datum);
};

#endif // STATISTICS_HPP