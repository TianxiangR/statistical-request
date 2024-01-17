#ifndef TEST_UTILS
#define TEST_UTILS
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <functional>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#define LIGHTGREY "\x1b[90m"          /* Light Grey */

void assertTrue(const bool &actual)
{
  if (!actual)
    throw std::runtime_error("Expected: " + std::string(CYAN) + "true" + RESET + "\nReceived: " + std::string(CYAN) + "false" + RESET + "\n");
}

void assertFalse(const bool &actual)
{
  if (actual)
    throw std::runtime_error("Expected: " + std::string(CYAN) + "false" + RESET + "\nReceived: " + std::string(CYAN) + "true" + RESET + "\n");
}

template <typename T>
void assertEqual(const T &actual, const T &expected)
{
  if (actual != expected)
    throw std::runtime_error("Expected: " + std::string(CYAN) + std::to_string(expected) + RESET + "\nReceived: " + std::string(CYAN) + std::to_string(actual) + RESET + "\n");
}

template <typename T>
void assertNotEqual(const T &actual, const T &expected)
{
  if (actual == expected)
    throw std::runtime_error("Expected " + std::string(CYAN) + "not " + std::to_string(expected) + RESET + "\nReceived: " + std::string(CYAN) + std::to_string(actual) + RESET + "\n");
}

void test(const std::string &testName, const std::function<void()> &testFunction)
{
  try
  {
    testFunction();
    std::cout << GREEN << "PASSED: " << LIGHTGREY << testName << RESET << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << RED << "FAILED: " << RESET << testName << std::endl;
    std::cout << e.what() << std::endl;
  }
}

void describe(const std::string &description, const std::function<void()> &testFunction)
{
  std::cout << description << std::endl;
  testFunction();
}

#endif // TEST_UTILS