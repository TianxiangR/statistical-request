#ifndef STATISTICALREQUEST_HPP
#define STATISTICALREQUEST_HPP
#include "Request.hpp"
#include "Statistics.hpp"
#include <chrono>
#include <vector>
#include <unordered_map>

/**
 * @brief a request class that does statistical analysis: mean response time,
 *       standard deviation, and normal histogram.
 *
 */
class StatisticalRequest : public Request
{
private:
  std::unordered_map<std::string, Statistics> m_statistics;
  std::chrono::high_resolution_clock::time_point m_startTime;
  std::string m_uri;

public:
  StatisticalRequest() : Request() {}
  virtual ~StatisticalRequest() = default;
  double getMeanResponseTime(const std::string &uri) const;
  double getStandardDeviation(const std::string &uri) const;

protected:
  void start(const std::string &uri) override;
  void finish() override;
};

#endif // STATISTICALREQUEST_HPP
