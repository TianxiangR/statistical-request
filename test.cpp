#include "StatisticalRequest.hpp"
#include "Statistics.hpp"
#include "testUtils.cpp"
#include <iostream>
#include <cmath>

int main()
{
  describe("Statistics", []()
           {
    test("getMean returns 0 when no data has been added", [](){
      Statistics statistics;
      assertEqual(statistics.getMean(), 0.0);
    });

    test("getMean returns the mean of the data", [](){
      Statistics statistics;
      statistics.addData(1.0);
      statistics.addData(2.0);
      statistics.addData(3.0);
      assertEqual(statistics.getMean(), 2.0);
    }); 
    
    test("getStandardDeviation returns 0 when no data has been added", [](){
      Statistics statistics;
      assertEqual(statistics.getStandardDeviation(), 0.0);
    });

    test("getStandardDeviation returns the standard deviation of the data", [](){
      Statistics statistics;
      statistics.addData(1.0);
      statistics.addData(2.0);
      statistics.addData(3.0);
      assertEqual(statistics.getStandardDeviation(), sqrt(2.0/3));
    }); });      
}