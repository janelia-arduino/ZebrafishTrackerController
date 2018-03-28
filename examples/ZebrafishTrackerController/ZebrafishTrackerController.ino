#include <ZebrafishTrackerController.h>


ZebrafishTrackerController dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
