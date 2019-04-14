/*
  ==============================================================================

    ZeroConfTests.h
    Created: 14 Apr 2019 12:41:40pm
    Author:  Alex Gustafson

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.
 BEGIN_JUCE_MODULE_DECLARATION
  ID:               diaupro_monitor
  vendor:
  version:          1.0.0
  name:             ZeroConf Networking | Monitor Module
  description:      Part of a module that allows distributed audio processing
  website:          https://github.com/alexgustafson/Diaupro
  license:          MIT
  dependencies:     juce_core
 END_JUCE_MODULE_DECLARATION
*******************************************************************************/


#pragma once
#define DIAUPRO_MONITOR_H_INCLUDED

#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

#include <juce_core/juce_core.h>

using namespace juce;

class FileDescriptorListener
{
public:
    explicit FileDescriptorListener(const String& _listenerName) : listenerName (_listenerName) {};
    virtual ~FileDescriptorListener() {};
    virtual void handleFileDescriptor(int fileDescriptor) = 0;
    String getFileDescriptorListenerName() { return this->listenerName; };
private:
    String listenerName;
};

class Monitor : public FileDescriptorListener, juce::Thread
{
public:
    Monitor();
    ~Monitor();

    void initializeControlSocket();
    void addFileDescriptorAndListener(int fileDescriptor, FileDescriptorListener* listener, juce::String debugMessage = "");
    void removeFileDescriptorAndListener(int fileDescriptor, bool shoudlClose=false);
    void startMonitoring();
    void stop();

    void handleFileDescriptor(int fileDescriptor) override;

private:
    fd_set readset, writeset, exset;
    HashMap<int, FileDescriptorListener *> map;
    int maxfd;
    int control_listener;
    int control_send;
    struct sockaddr control_address;
    socklen_t len_control_address;

    void run() override;
    int control_socket_port;

    juce::Array<int> fileDescriptors;
    juce::CriticalSection lock;

    ScopedPointer<DatagramSocket> listenSocket, controlSocket;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Monitor)
};

