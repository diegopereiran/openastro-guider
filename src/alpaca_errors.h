/*
 *  alpaca_errors.h
 *  PHD Guiding
 *
 *  Which Alpaca errors from a capture call mean the server has lost the camera.
 *  Kept free of wx so it can be unit tested (tests/camera/test_alpaca_errors.cpp).
 */

#ifndef ALPACA_ERRORS_H_INCLUDED
#define ALPACA_ERRORS_H_INCLUDED

namespace AlpacaErrors
{
// ASCOM NotConnectedException (0x407)
const long kNotConnected = 0x407;

// True when a capture call failed because the server reports the camera as not
// connected: the camera must be disconnected and reconnected (issue #103).
bool CaptureNeedsReconnect(long errorNumber);
}

#endif
