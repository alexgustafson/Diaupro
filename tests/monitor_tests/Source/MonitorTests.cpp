/*
  ==============================================================================

    MonitorTests.cpp
    Created: 14 Apr 2019
    Author:  Alex Gustafson

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

void MonitorTests::startUpAndShutDownTest()
{
    beginTest("Start Up and Shut Down Test");

    Monitor monitor;
    monitor.startMonitoring();

    Thread::sleep(200);

    monitor.stop();

    Thread::sleep(100); // wait for thread to stop

}