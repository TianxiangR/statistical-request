#ifndef STATISTICALREQUEST_HPP
#define STATISTICALREQUEST_HPP
#include "Request.hpp"
#include "Statistics.hpp"
#include <chrono>
#include <vector>
#include <unordered_map>

/**
 *  a request class that does statistical analysis: mean response time,
 *  standard deviation, and normal histogram.
 *
 */
class StatisticalRequest : public Request
{
private:
    // the response time statistics for each uri
    std::unordered_map<std::string, Statistics> m_statistics;
    // the start time of the current processing request
    std::chrono::high_resolution_clock::time_point m_startTime;
    // the uri being currently processeds
    std::string m_uri;
    // the maximum number of bins for the histogram
    int m_max_bins;

public:
    StatisticalRequest(const int &bins) : Request(), m_max_bins(bins) {}
    ~StatisticalRequest() = default;

    /**
     * Get the mean response time in microseconds for a given uri
     *
     * @param [in] uri The URI of the request endpoint
     * @return the mean response time in microseconds
     */
    double getMeanResponseTime(const std::string &uri) const;

    /**
     * Get the standard deviation of the response time in microseconds for a given uri
     *
     * @param [in] uri The URI of the request endpoint
     * @return the standard deviation of the response time in microseconds
     */
    double getStandardDeviation(const std::string &uri) const;

    /**
     * Get the normalized histogram of the response time for a given uri
     *
     * @param [in] uri The URI of the request endpoint
     * @return the normalized histogram of the response time
     */
    std::string getNormalizedHistogram(const std::string &uri) const;

protected:
    void start(const std::string &uri) override;
    void finish() override;
};

#endif // STATISTICALREQUEST_HPP