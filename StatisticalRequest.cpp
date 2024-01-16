#include "StatisticalRequest.hpp"

void StatisticalRequest::start(const std::string &uri)
{
  m_startTime = std::chrono::high_resolution_clock::now();
}

void StatisticalRequest::finish()
{
  auto endTime = std::chrono::high_resolution_clock::now();
  m_totalResponseTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_startTime);
  m_processedRequests++;
}

int64_t StatisticalRequest::getMeanResponseTime() const
{
  return m_processedRequests > 0 ? m_totalResponseTime.count() / m_processedRequests : 0;
}