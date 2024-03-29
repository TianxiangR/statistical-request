#include "StatisticalRequest.hpp"
#include <cmath>
#include <stdexcept>

StatisticalRequest::StatisticalRequest(const int &max_bins) : Request(), m_max_bins(max_bins)
{
    if (m_max_bins < 1)
        throw std::invalid_argument("bins must be greater than 0");
}

void StatisticalRequest::start(const std::string &uri)
{
    // record the start time and uri for the currently processing request
    m_startTime = std::chrono::high_resolution_clock::now();
    m_uri = uri;
}

void StatisticalRequest::finish()
{
    // record the end time and calculate the response time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto responseTime =
        std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_startTime);

    // add the response time to the statistics for the uri
    if (m_statistics.find(m_uri) == m_statistics.end())
    {
        m_statistics[m_uri] = Statistics(m_max_bins);
        m_statistics[m_uri].addData(responseTime.count());
    }
    else
    {
        m_statistics[m_uri].addData(responseTime.count());
    }
}

double StatisticalRequest::getMeanResponseTime(const std::string &uri) const
{
    if (m_statistics.find(uri) == m_statistics.end())
        return 0.0;
    return m_statistics.at(uri).getMean();
};

double StatisticalRequest::getStandardDeviation(const std::string &uri) const
{
    if (m_statistics.find(uri) == m_statistics.end())
        return 0.0;
    return m_statistics.at(uri).getStandardDeviation();
};

std::string StatisticalRequest::getNormalizedHistogram(const std::string &uri) const
{
    if (m_statistics.find(uri) == m_statistics.end())
        return "";

    return m_statistics.at(uri).getNormalizedHistogram();
};