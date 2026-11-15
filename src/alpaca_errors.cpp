/*
 *  alpaca_errors.cpp
 *  PHD Guiding
 *
 *  See alpaca_errors.h.
 */

#include "alpaca_errors.h"

namespace AlpacaErrors
{
bool CaptureNeedsReconnect(long errorNumber)
{
    return errorNumber == kNotConnected;
}
}
