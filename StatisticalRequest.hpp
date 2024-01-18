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
  std::unordered_map<std::string, Statistics> m_statistics;   // the response time statistics for each uri
  std::chrono::high_resolution_clock::time_point m_startTime; // the start time of the current processing
  std::string m_uri;                                          // the uri being currently processeds

public:
  StatisticalRequest() : Request() {}
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

protected:
  void start(const std::string &uri) override;
  void finish() override;
};

#endif // STATISTICALREQUEST_HPP
