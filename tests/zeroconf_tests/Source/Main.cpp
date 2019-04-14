/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "./ZeroConfTests.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
int main (int argc, char* argv[])
{

    static ZeroConfTests zeroConfTests;
    UnitTestRunner runner;
    runner.setAssertOnFailure(false);
    runner.runAllTests();

    return 0;
}
