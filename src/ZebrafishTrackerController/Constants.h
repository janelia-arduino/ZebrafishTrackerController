// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef ZEBRAFISH_TRACKER_CONTROLLER_CONSTANTS_H
#define ZEBRAFISH_TRACKER_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <StageController.h>

#include <AnalogController.h>


namespace zebrafish_tracker_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=1};

enum{EVENT_COUNT_MAX=8};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

enum{CHANNEL_COUNT=2};

extern const bool use_drivers;

extern const size_t analog_update_delay;
extern const size_t analog_update_period;

extern const long stage_position_midpoint;
extern const long analog_value_max;

// Clients
extern const size_t analog_controller_address[1];

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const long channel_count;

extern const long steps_per_position_units_element_default;
extern const long steps_per_position_units_default[CHANNEL_COUNT];

extern const long velocity_max_element_default;
extern const long velocity_max_default[CHANNEL_COUNT];

extern const long velocity_min_element_default;
extern const long velocity_min_default[CHANNEL_COUNT];

extern const long acceleration_max_element_default;
extern const long acceleration_max_default[CHANNEL_COUNT];

extern const long home_velocity_element_default;
extern const long home_velocity_default[CHANNEL_COUNT];

extern const long stage_position_min_element_default;
extern const long stage_position_min_default[CHANNEL_COUNT];

extern const long stage_position_max_element_default;
extern const long stage_position_max_default[CHANNEL_COUNT];

// Parameters

// Functions

// Callbacks

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
