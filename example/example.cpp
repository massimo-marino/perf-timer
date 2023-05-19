//
// example.cpp
//
#include "../perf-timer.h"

#include <iostream>
#include <chrono>
#include <thread>
////////////////////////////////////////////////////////////////////////////////
static void testPerfTimer(std::function<void()> fun, const std::string& funName) {
  // run the function in the perf-timer
  double seconds { perftimer_t<>::duration_secs(fun).count() };
  seconds = perftimer_t<>::duration_secs(fun).count();

  auto ns { perftimer_t<>::duration(fun).count() };
  ns = perftimer_t<>::duration(fun).count();

  auto musec { perftimer_t<std::chrono::microseconds>::duration(fun).count() };
  musec = perftimer_t<std::chrono::microseconds>::duration(fun).count();

  auto msec { perftimer_t<std::chrono::milliseconds>::duration(fun).count() };
  msec = perftimer_t<std::chrono::milliseconds>::duration(fun).count();

  std::cout << "\n1. " << funName << " took: " << seconds << " secs.\n";
  std::cout << "2. " << funName << " took: " << ns << " nsec.\n";
  std::cout << "3. " << funName << " took: " << musec << " microsec.\n";
  std::cout << "4. " << funName << " took: " << msec << " msec.\n";
}

int main () {
  // define a function that doubles its integer argument and returns the result
  std::function<int(const int)> doubleInt = [] (const int x) { return (2 * x); };

  const int in {128};

  // more verbose
  //  double seconds { perftimer_t<>::duration_secs(doubleInt, in).count() };
  //  seconds = perftimer_t<>::duration_secs(doubleInt, in).count();
  //  long ns { perftimer_t<>::duration(doubleInt, in).count() };
  //  ns = perftimer_t<>::duration(doubleInt, in).count();
  //  long musec { perftimer_t<std::chrono::microseconds>::duration(doubleInt, in).count() };
  //  musec = perftimer_t<std::chrono::microseconds>::duration(doubleInt, in).count();
  //  long msec { perftimer_t<std::chrono::milliseconds>::duration(doubleInt, in).count() };
  //  msec = perftimer_t<std::chrono::milliseconds>::duration(doubleInt, in).count();

  // less verbose
  double seconds { duration_secs(doubleInt, in) };
  seconds = duration_secs(doubleInt, in);

  long ns { duration_nsec(doubleInt, in) };
  ns = duration_nsec(doubleInt, in);

  long musec { duration_microsec(doubleInt, in) };
  musec = duration_microsec(doubleInt, in);

  long msec { duration_msec(doubleInt, in) };
  msec = duration_msec(doubleInt, in);

  auto v { doubleInt(in) };
  std::cout << "\n1. doubleInt(" << in << ") took: " << seconds << " secs. - value: " << v << "\n";
  std::cout << "2. doubleInt(" << in << ") took: " << ns << " nsec.\n";
  std::cout << "3. doubleInt(" << in << ") took: " << musec << " microsec.\n";
  std::cout << "4. doubleInt(" << in << ") took: " << msec << " msec.\n";

/////

  // define a simple function as a lambda
  std::function<void()> doNothing = [] () {};
  testPerfTimer(doNothing, "doNothing");

  // define a simple function that sleeps for 250 milliseconds as a lambda
  std::function<void()> sleep250MilliSeconds = [] () { std::this_thread::sleep_for(250ms); };
  testPerfTimer(sleep250MilliSeconds, "sleep250MilliSeconds");

  // define a simple function that sleeps for 500 milliseconds as a lambda
  std::function<void()> sleepHalfSecond = [] () { std::this_thread::sleep_for(500ms); };
  testPerfTimer(sleepHalfSecond, "sleepHalfSecond");

  // define a simple function that sleeps for 1 second as a lambda
  std::function<void()> sleepOneSecond = [] () { std::this_thread::sleep_for(1000ms); };
  testPerfTimer(sleepOneSecond, "sleepOneSecond");

  // define a simple function that sleeps for 2 seconds as a lambda
  std::function<void()> sleepTwoSeconds = [] () { std::this_thread::sleep_for(2000ms); };
  testPerfTimer(sleepTwoSeconds, "sleepTwoSeconds");

  return 0;
}
