/*
 * SpinTimerSysTickUptimeInfoAdapter.h
 *
 *  Created on: 20.09.2023
 *      Author: dniklaus
 */

#ifndef SpinTimerSysTickUptimeInfoAdapter_H_
#define SpinTimerSysTickUptimeInfoAdapter_H_

#include "SpinTimerUptimeInfoAdapter.h"

typedef struct SpinTimerSysTickUptimeInfoAdapter SpinTimerSysTickUptimeInfoAdapter;

/**
 * @brief Adapter Interface.
 * @details Implementations of call-outs to get the platform specific up-time info time every system tick.
 */
struct SpinTimerSysTickUptimeInfoAdapter
{
    SpinTimerUptimeInfoAdapter super;   /*!< Base class @ref SpinTimerUptimeInfoAdapter. */
};

/* Function prototypes */
/**
 * @brief Constructor.
 * 
 * @return SpinTimerSysTickUptimeInfoAdapter* 
 */
SpinTimerSysTickUptimeInfoAdapter* SpinTimerSysTickUptimeInfoAdapter_create();

/**
 * @brief Initializer.
 * 
 * @param me Pointer to this SpinTimerSysTickUptimeInfoAdapter object.
 */
void SpinTimerSysTickUptimeInfoAdapter_init(SpinTimerSysTickUptimeInfoAdapter* const me);

/**
 * @brief Destructor.
 * 
 * @param me Pointer to this SpinTimerSysTickUptimeInfoAdapter object.
 */
void SpinTimerSysTickUptimeInfoAdapter_destroy(SpinTimerSysTickUptimeInfoAdapter* const me);

/**
 * @brief 
 * 
 * @param me Pointer to this SpinTimerSysTickUptimeInfoAdapter object.
 * @return uint32_t 
 */
uint32_t SpinTimerSysTickUptimeInfoAdapter_currentTimeMicros(SpinTimerSysTickUptimeInfoAdapter const* const me);

/**
 * @brief 
 * 
 * @param me Pointer to this SpinTimerSysTickUptimeInfoAdapter object.
 * @return uint32_t 
 */
uint32_t SpinTimerSysTickUptimeInfoAdapter_microsPerTick(SpinTimerSysTickUptimeInfoAdapter const* const me);

/**
 * @brief Update the current time count time base.
 * @details Helper function running in interrupt context. 
 */
void SpinTimerSysTickUptimeInfoAdapter_updateTickCount();

#endif
