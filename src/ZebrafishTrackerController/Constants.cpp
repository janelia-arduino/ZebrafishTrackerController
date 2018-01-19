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

// Interrupts

// Units

// Properties

// Parameters

// Functions

// Callbacks

// Errors
}
}
