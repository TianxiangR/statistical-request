#include "Request.hpp"

/**
 * @brief a request class that does statistical analysis: mean response time,
 *       standard deviation, and normal histogram.
 *
 */
class StatisticalRequest : public Request
{
public:
  StatisticalRequest() : Request() {}
  virtual ~StatisticalRequest() = default;

protected:
  void start(const std::string &uri) override;
  void finish() override;
};
