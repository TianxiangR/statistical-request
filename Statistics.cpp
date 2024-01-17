#include "Statistics.hpp"
#include <cmath>

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