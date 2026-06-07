// TODO: add license

#include "scr_hawkeye.h"

typedef enum {
    FSM_NOOP = 0,
    FSM_UPDATE = 1,
    FSM_ERR_NULLPTR = 2,
} FSM_Err_t;

// detects launch using acceleration
FSM_Err_t HWK_FSM_launchDetectAccel(float accelMag,
                                    uint8_t* counter,
                                    const uint8_t reqCount,
                                    const float accelThresh
);

// TODO:
// detects launch using altitude
FSM_Err_t HWK_FSM_launchDetectAlt(float alt,
                                  uint8_t* counter,
                                  const uint8_t reqCount
);

// detects apogee using alt and derived velocity
FSM_Err_t HWK_FSM_apogeeDetectAltVel(float alt,
                                     uint64_t time,
                                     uint8_t* counter,
                                     const uint8_t reqCount,
                                     const float negVelThresh);

// detects landing using altitude
FSM_Err_t HWK_FSM_landingDetectAlt(float alt,
                                   uint8_t* counter,
                                   const uint8_t reqCount,
                                   const uint8_t divThr);
