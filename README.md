# Statistical Request - Enhanced Request Handling

## About the Project

The Astiri platform's Product Manager, responding to user feedback, aims to bolster the system's capabilities in understanding request response times. The focus is on recording response times, calculating the mean response time, determining the standard deviation of response times, and generating a normalized histogram on a per URI basis.

## Usage

#### Recording Response Times

Each time you call the `process` method, the processing time will be recorded and saved into a private data member.

#### Retreiving Mean Response Time

By calling the `getMeanResponseTime` method, you will get the mean resposne time of an URI.

```cpp
StatisticalRequest statisticalRequest(4);
for (int i = 0; i < 100; i++)
    statisticalRequest.process("uri1");

double meanResponseTime = statisticalRequest.getMeanResponseTime("uri1");
```

#### Retreiving Standard Deviation of Response Times

By calling the `getStandardDeviation` method, you will get the standard deviation of response times of an URI.

```cpp
StatisticalRequest statisticalRequest(4);
for (int i = 0; i < 100; i++)
    statisticalRequest.process("uri1");

double standardDeviation = statisticalRequest.getStandardDeviation("uri1")
```

#### Retreiving Normalized Hitogram of Response Times

```cpp
StatisticalRequest statisticalRequest(4);
for (int i = 0; i < 100; i++)
    statisticalRequest.process("uri1");

std::cout << statisticalRequest.getNormalizedHistogram("uri1") << std::endl;
```

Sample output:
```
0.00-0.25 | * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
0.25-0.50 | * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
0.50-0.75 | * * * * * * * * * * * * * * * * *
0.75-1.00 | * * * * * * * * * *
```

## Test

The unit tests are in `test.cpp`.

Runing the following command will compile the executable for unit tests.

```sh
make run-test
```
Then you will get a `test.exe` file. Type in the following command to run the unit tests.

```
.\test.exe
```


