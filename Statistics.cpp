#include "Statistics.hpp"
#include <cmath>
#include <algorithm>

Statistics::Statistics(const int &bins)
    : m_max_bins(bins) {}

double Statistics::getMean() const
{
    if (m_data.size() == 0)
        return 0;

    auto sum = 0.0;
    for (auto datum : m_data)
        sum += datum;
    return sum / m_data.size();
}

double Statistics::getStandardDeviation() const
{
    if (m_data.size() == 0)
        return 0;

    auto mean = getMean();
    auto sum = 0.0;
    for (auto datum : m_data)
    {
        auto diff = datum - mean;
        sum += diff * diff;
    }
    return sqrt(sum / m_data.size());
}

void Statistics::addData(const double &datum)
{
    m_data.push_back(datum);
}

std::string Statistics::doubleToTwoDecimalPlaces(const double &value) const
{
    std::string str = std::to_string(value);
    auto pos = str.find('.');
    if (pos == std::string::npos)
        return str + ".00";

    auto decimalPlaces = str.size() - pos - 1;
    if (decimalPlaces == 1)
        return str + "0";

    return str.substr(0, pos + 3);
}

std::string Statistics::getNormalizedHistogram() const
{
    if (m_data.size() == 0)
        return "";

    // normalize data
    double min = m_data[0];
    double max = m_data[0];

    for (auto datum : m_data)
    {
        if (datum < min)
            min = datum;
        if (datum > max)
            max = datum;
    }

    double range = max - min;
    std::vector<double> normalized_data;

    for (auto datum : m_data)
        normalized_data.push_back((datum - min) / range);

    // create histogram
    double binSize = 1.0 / m_max_bins;
    std::vector<int> bins(m_max_bins, 0);

    for (auto datum : normalized_data)
    {
        int bin = datum / binSize;
        if (bin == m_max_bins)
            bin--;
        bins[bin]++;
    }

    // create histogram string
    std::string histogram = "";

    for (int i = 0; i < m_max_bins; i++)
    {
        histogram += doubleToTwoDecimalPlaces(i * binSize) + "-" + doubleToTwoDecimalPlaces((i + 1) * binSize) + " | ";
        for (int j = 0; j < bins[i]; j++)
            histogram += "* ";
        histogram += "\n";
    }

    return histogram;
}