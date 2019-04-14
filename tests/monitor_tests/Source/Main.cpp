/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MonitorTests.h"

//==============================================================================
int main (int argc, char* argv[])
{

    static MonitorTests monitorTests;
    UnitTestRunner runner;
    runner.setAssertOnFailure(false);
    runner.runAllTests();


    return 0;
}
