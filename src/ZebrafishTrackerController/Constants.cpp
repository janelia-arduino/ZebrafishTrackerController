// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
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
  .version_minor=0,
  .version_patch=0,
};

const bool use_drivers = false;

// Pins

// Units

// Properties
const long channel_count = CHANNEL_COUNT;

const long steps_per_position_units_default[CHANNEL_COUNT] =
{
  1,
  1,
};

const long velocity_max_default[CHANNEL_COUNT] =
{
  999999,
  999999,
};

const long velocity_min_default[CHANNEL_COUNT] =
{
  20000,
  20000,
};

const long acceleration_max_default[CHANNEL_COUNT] =
{
  1000000,
  1000000,
};

const long home_velocity_default[CHANNEL_COUNT] =
{
  -50000,
  -50000,
};

const long stage_position_min_default[CHANNEL_COUNT] =
{
  0,
  0,
};

const long stage_position_max_default[CHANNEL_COUNT] =
{
  100000,
  100000,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
