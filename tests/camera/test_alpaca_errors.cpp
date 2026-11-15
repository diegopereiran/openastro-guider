// Alpaca capture error tests (open-astro/openastro-guider#103).
//
// When the guide camera drops off USB, AlpacaBridge sets connected=false and
// answers every capture call with error 1031 (NotConnectedException).
// CameraAlpaca::Capture must then disconnect the camera with RECONNECT, so the
// EquipmentDisconnected event goes out with reconnecting:true and the existing
// auto-reconnect runs. Any other error keeps the old alert-and-retry behavior.

#include <gtest/gtest.h>

#include "alpaca_errors.h"

TEST(AlpacaErrors, NotConnectedNeedsReconnect)
{
    EXPECT_EQ(AlpacaErrors::kNotConnected, 1031);
    EXPECT_TRUE(AlpacaErrors::CaptureNeedsReconnect(1031));
}

TEST(AlpacaErrors, OtherErrorsKeepTodaysBehavior)
{
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(0));    // no Alpaca error (curl failure)
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(1024)); // NotImplemented
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(1025)); // InvalidValue
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(1035)); // InvalidOperation
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(1280)); // driver error
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(400));  // HTTP status
    EXPECT_FALSE(AlpacaErrors::CaptureNeedsReconnect(500));  // HTTP status
}
