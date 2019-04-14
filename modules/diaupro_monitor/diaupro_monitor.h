/*
  ==============================================================================

    diaupro_monitor.h
    Created: 14 Apr 2019
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

#include <juce_core/juce_core.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>


using namespace juce;
#include "Monitor/Monitor.h"


