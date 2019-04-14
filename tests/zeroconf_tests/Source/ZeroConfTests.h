/*
  ==============================================================================

    ZeroConfTests.h
    Created: 14 Apr 2019 12:41:40pm
    Author:  Alex

  ==============================================================================
*/

#pragma once

#include <diaupro_zeroconf/ZeroConf/ZeroConfManager.h>
#include "JuceHeader.h"


class ZeroConfTests : public UnitTest {
public:
    ZeroConfTests() : UnitTest("") {
    }

    void firstTest();

    void browseTest();

    void runTest();

private:

    class ZeroConfObserver : public ZeroConfListener {
    public:

        ZeroConfObserver() {
        };

        ~ZeroConfObserver() {
        };

        void handleZeroConfUpdate(OwnedArray<ZeroConfService, CriticalSection> *serviceList) {
            Logger::writeToLog("notified");
            for (int i = 0; i < serviceList->size(); i++) {
                ZeroConfService *service = serviceList->getUnchecked(i);
                String status = service->status == ZeroConfService::ResultStatus::queryResult ? "final" : "unfinished";
                Logger::writeToLog(String::formatted("Found service %s %s %s:%d %s", service->getRegType().toRawUTF8(), service->getServiceName().toRawUTF8(), service->ip.toRawUTF8(), service->getPort(), status.toRawUTF8()));
            }
        }

    private:
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ZeroConfTests)
};

