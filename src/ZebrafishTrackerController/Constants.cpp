// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace zebrafish_tracker_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"zebrafish_tracker_controller");

CONSTANT_STRING(firmware_name,"ZebrafishTrackerController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=1,
  .version_patch=2,
};

const bool use_drivers = false;

const size_t analog_update_delay = 1000;
const size_t analog_update_period = 10;

const long stage_position_midpoint = 50000;
const long analog_value_max = 32767;

// Clients
const size_t analog_controller_address[1] =
{
  3,
};

// Pins

// Units

// Properties
const long channel_count = CHANNEL_COUNT;

const long steps_per_position_units_element_default = 1;
const long steps_per_position_units_default[CHANNEL_COUNT] =
{
  steps_per_position_units_element_default,
  steps_per_position_units_element_default,
};

const long velocity_max_element_default = 999999;
const long velocity_max_default[CHANNEL_COUNT] =
{
  velocity_max_element_default,
  velocity_max_element_default,
};

const long velocity_min_element_default = 20000;
const long velocity_min_default[CHANNEL_COUNT] =
{
  velocity_min_element_default,
  velocity_min_element_default,
};

const long acceleration_max_element_default = 1000000;
const long acceleration_max_default[CHANNEL_COUNT] =
{
  acceleration_max_element_default,
  acceleration_max_element_default,
};

const long home_velocity_element_default = -50000;
const long home_velocity_default[CHANNEL_COUNT] =
{
  home_velocity_element_default,
  home_velocity_element_default,
};

const long stage_position_min_element_default = 0;
const long stage_position_min_default[CHANNEL_COUNT] =
{
  stage_position_min_element_default,
  stage_position_min_element_default,
};

const long stage_position_max_element_default = stage_position_midpoint*2;
const long stage_position_max_default[CHANNEL_COUNT] =
{
  stage_position_max_element_default,
  stage_position_max_element_default,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
