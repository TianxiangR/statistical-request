#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <vector>

class Statistics
{
private:
  std::vector<double> m_data;

public:
  double getMean() const;

  double getStandardDeviation() const;

  void addData(const double &datum);
};

#endif // STATISTICS_HPP