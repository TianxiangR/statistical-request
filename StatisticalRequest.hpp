#include "Request.hpp"
#include <chrono>

/**
 * @brief a request class that does statistical analysis: mean response time,
 *       standard deviation, and normal histogram.
 *
 */
class StatisticalRequest : public Request
{
private:
  size_t m_processedRequests = 0;
  std::chrono::microseconds m_totalResponseTime = std::chrono::microseconds(0);
  std::chrono::high_resolution_clock::time_point m_startTime;

public:
  StatisticalRequest() : Request() {}
  virtual ~StatisticalRequest() = default;
  int64_t getMeanResponseTime() const;

protected:
  void start(const std::string &uri) override;
  void finish() override;
};
