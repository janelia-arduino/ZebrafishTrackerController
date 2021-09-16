// ----------------------------------------------------------------------------
// ZebrafishTrackerController.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef ZEBRAFISH_TRACKER_CONTROLLER_H
#define ZEBRAFISH_TRACKER_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <EventController.h>

#include <ModularClient.h>
#include <AnalogController.h>

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

  EventController<zebrafish_tracker_controller::constants::EVENT_COUNT_MAX> event_controller_;
  ModularClient * analog_controller_ptr_;

  StageController::PositionArray position_array_prev_;

  // Handlers
  void updateAnalogEventHandler(int arg);

};

#endif
