// ----------------------------------------------------------------------------
// ZebrafishTrackerController.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../ZebrafishTrackerController.h"


using namespace zebrafish_tracker_controller;

ZebrafishTrackerController::ZebrafishTrackerController()
{
}

void ZebrafishTrackerController::setup()
{
  // Parent Setup
  StageController::setup(constants::use_drivers);

  // Reset Watchdog
  resetWatchdog();

  // Variable Setup

  // Event Controller Setup
  event_controller_.setup();

  // Clients Setup
  dac_controller_ptr_ = &(createClientAtAddress(constants::dac_controller_address));
  dac_controller_ptr_->setName(dac_controller::constants::device_name);

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Pins

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties
  modular_server::Property & channel_count_property = modular_server_.property(step_dir_controller::constants::channel_count_property_name);
  channel_count_property.setDefaultValue(constants::channel_count);
  channel_count_property.setRange(constants::channel_count,constants::channel_count);

  modular_server::Property & steps_per_position_units_property = modular_server_.property(step_dir_controller::constants::steps_per_position_units_property_name);
  steps_per_position_units_property.setDefaultValue(constants::steps_per_position_units_default);

  modular_server::Property & velocity_max_property = modular_server_.property(step_dir_controller::constants::velocity_max_property_name);
  velocity_max_property.setDefaultValue(constants::velocity_max_default);

  modular_server::Property & velocity_min_property = modular_server_.property(step_dir_controller::constants::velocity_min_property_name);
  velocity_min_property.setDefaultValue(constants::velocity_min_default);

  modular_server::Property & acceleration_max_property = modular_server_.property(step_dir_controller::constants::acceleration_max_property_name);
  acceleration_max_property.setDefaultValue(constants::acceleration_max_default);

  modular_server::Property & home_velocity_property = modular_server_.property(step_dir_controller::constants::home_velocity_property_name);
  home_velocity_property.setDefaultValue(constants::home_velocity_default);

  modular_server::Property & stage_position_min_property = modular_server_.property(stage_controller::constants::stage_position_min_property_name);
  stage_position_min_property.setDefaultValue(constants::stage_position_min_default);

  modular_server::Property & stage_position_max_property = modular_server_.property(stage_controller::constants::stage_position_max_property_name);
  stage_position_max_property.setDefaultValue(constants::stage_position_max_default);

  // Parameters

  // Functions

  // Callbacks

  for (size_t channel=0;channel<constants::CHANNEL_COUNT;++channel)
  {
    position_array_prev_.push_back(0);
  }

  EventId dac_update_event_id = event_controller_.addInfiniteRecurringEventUsingDelay(makeFunctor((Functor1<int> *)0,*this,&ZebrafishTrackerController::updateDacEventHandler),
    constants::dac_update_delay,
    constants::dac_update_period);
  event_controller_.enable(dac_update_event_id);
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void ZebrafishTrackerController::updateDacEventHandler(int arg)
{
  StageController::PositionArray array = getStagePosition();

  bool position_changed = false;
  for (size_t channel=0;channel<array.size();++channel)
  {
    if (array[channel] != position_array_prev_[channel])
    {
      position_changed = true;
    }
    position_array_prev_[channel] = array[channel];
  }
  if (!position_changed)
  {
    return;
  }

  for (size_t channel=0;channel<array.size();++channel)
  {
    long position_shifted = array[channel] - constants::stage_position_midpoint;
    long dac_value = (position_shifted * constants::dac_value_max) / constants::stage_position_midpoint;
    array[channel] = dac_value;
  }
  dac_controller_ptr_->call(dac_controller::constants::set_dac_values_function_name,array);
}
