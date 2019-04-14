/*
  ==============================================================================

    Monitor.h
    Created: 14 Apr 2019
    Author:  Alex Gustafson

  ==============================================================================
*/
#pragma once

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

