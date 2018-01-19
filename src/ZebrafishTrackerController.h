// ----------------------------------------------------------------------------
// ZebrafishTrackerController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ZEBRAFISH_TRACKER_CONTROLLER_H
#define ZEBRAFISH_TRACKER_CONTROLLER_H
#include <Flash.h>
#include <EEPROM.h>
#include <Streaming.h>
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <MemoryFree.h>
#include <ConstantVariable.h>
#include <SavedVariable.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>
#include <Watchdog.h>

#include <ModularClient.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <StepDirController.h>
#include <StageController.h>

#include "ZebrafishTrackerController/Constants.h"


class ZebrafishTrackerController : public StageController
{
public:
  ZebrafishTrackerController();
  virtual void setup();

private:
  modular_server::Property properties_[zebrafish_tracker_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[zebrafish_tracker_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[zebrafish_tracker_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[zebrafish_tracker_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers

};

#endif
