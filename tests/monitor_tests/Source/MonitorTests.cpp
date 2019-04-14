/*
  ==============================================================================

    MonitorTests.cpp
    Created: 14 Apr 2019 3:46:59pm
    Author:  Alex

  ==============================================================================
*/

#include "MonitorTests.h"


void MonitorTests::firstTest()
{
    beginTest("Testing The Tester");
    expect(true);
    expectEquals(1, 1);
}

void MonitorTests::runTest()
{
    firstTest();

}