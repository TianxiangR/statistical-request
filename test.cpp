#include "StatisticalRequest.hpp"
#include "Statistics.hpp"
#include "testUtils.cpp"
#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

#define ERROR 100

using namespace std;

int main()
{
  describe("Test Statistics", []()
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

  describe("Test StatisticalRequest", []()
           {
    test("getMeanResponseTime returns 0 when no data has been added", []()
         {
      StatisticalRequest statisticalRequest;
      assertEqual(statisticalRequest.getMeanResponseTime("uri"), 0.0); });

    test("getMeanResponseTime returns the mean of the data", []()
         {
      StatisticalRequest statisticalRequest;
      chrono::microseconds startTime = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now().time_since_epoch());
      statisticalRequest.process("uri1");
      statisticalRequest.process("uri1");
      chrono::microseconds endTime = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now().time_since_epoch());
      chrono::microseconds responseTime = endTime - startTime;

      assertTrue(statisticalRequest.getMeanResponseTime("uri1") >= responseTime.count() / 2 - ERROR); });

    test("processing another uri would not affect the mean of the previous uri", [](){
      StatisticalRequest statisticalRequest;
      statisticalRequest.process("uri1");
      double meanResponseTime1 = statisticalRequest.getMeanResponseTime("uri1");
      statisticalRequest.process("uri2");
      double meanResponseTime2 = statisticalRequest.getMeanResponseTime("uri1");

      // assert the mean response time of uri1 remains the same before and after processing uri2
      assertEqual(meanResponseTime1, meanResponseTime2); });

      
    test("getStandardDeviation returns 0 when no data has been added", [](){
      StatisticalRequest statisticalRequest;
      assertEqual(statisticalRequest.getStandardDeviation("uri"), 0.0); }); 
      
    test("getStandardDeviation returns the standard deviation of the data", [](){
      StatisticalRequest statisticalRequest;
      vector<double> responseTimes;

      // this test case is based on the trust on getMeanResponseTime, so we need to test getMeanResponseTime thoroughly first
      // throughout the calculations, we get the response time for each time we process the uri and store it in a vector
      statisticalRequest.process("uri1");
      responseTimes.push_back(statisticalRequest.getMeanResponseTime("uri1"));
      statisticalRequest.process("uri1");
      responseTimes.push_back(statisticalRequest.getMeanResponseTime("uri1") * 2 - responseTimes[0]);
      statisticalRequest.process("uri1");
      responseTimes.push_back(statisticalRequest.getMeanResponseTime("uri1") * 3 - responseTimes[0] - responseTimes[1]);

      // compute standard deviation
      double mean = statisticalRequest.getMeanResponseTime("uri1");
      double sum = 0.0;

      for (auto responseTime : responseTimes)
      {
        double diff = responseTime - mean;
        sum += diff * diff;
      }

      double standardDeviation = sqrt(sum / responseTimes.size());

      assertEqual(statisticalRequest.getStandardDeviation("uri1"), standardDeviation);
      }); });
}