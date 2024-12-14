//
// Created by KOZY on 11/11/2024.
//

#include "Utils.h"

Utils::Utils() : lastUpdatedTime(0) {}


bool Utils::eventTriggered(const double &interval) {
  double currentTime = GetTime();

  if (currentTime - lastUpdatedTime > interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}