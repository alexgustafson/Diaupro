/*
  ==============================================================================

    ZeroConfTests.cpp
    Created: 14 Apr 2019 12:41:40pm
    Author:  Alex

  ==============================================================================
*/

#include "ZeroConfTests.h"


void ZeroConfTests::firstTest() {

    beginTest("Testing the Tester");
    expect(true, "Testing Setup Failed");
    expectNotEquals(1, 2, "Testing Setup Failed");
}

void ZeroConfTests::browseTest()
{
    beginTest("Browse Test");
    Monitor monitor;
    monitor.startMonitoring();

    ZeroConfObserver listener;

    ScopedPointer<ZeroConfManager> zeroConfManager = new ZeroConfManager(&monitor, &listener);
    zeroConfManager->browseService("_diapro._udp");

    Thread::sleep(2000);
    /*
     Start consolue command:
     dns-sd -R "Mu Shu" _diapro._udp local 9904
    */
    int i = 0;
    while (i < 50) {
        i++;
        Thread::sleep(50);
    }

    monitor.stop();
}


void ZeroConfTests::runTest() {
    firstTest();
    browseTest();
}