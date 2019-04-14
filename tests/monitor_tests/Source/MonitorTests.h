/*
  ==============================================================================

    MonitorTests.h
    Created: 14 Apr 2019 3:46:59pm
    Author:  Alex

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class MonitorTests : public UnitTest
{
public:
    MonitorTests() : UnitTest("") { pool = new ThreadPool(50); }

    void firstTest();
    void runTest();

private:

    ScopedPointer<ThreadPool> pool;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MonitorTests)
};