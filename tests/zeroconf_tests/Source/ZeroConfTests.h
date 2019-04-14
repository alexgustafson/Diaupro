/*
  ==============================================================================

    ZeroConfTests.h
    Created: 14 Apr 2019 12:41:40pm
    Author:  Alex

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class ZeroConfTests : public UnitTest
{
public:
    ZeroConfTests() : UnitTest("") {}
    void firstTest();
    void browseTest();
    void runTest();

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ZeroConfTests)
};

