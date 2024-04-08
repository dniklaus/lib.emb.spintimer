/*
 * SysTickUptimeInfoAdapter.h
 *
 *  Created on: 20.09.2023
 *      Author: dniklaus
 */

#ifndef SysTickUptimeInfoAdapter_H_
#define SysTickUptimeInfoAdapter_H_

#include "SpinTimerUptimeInfoAdapter.h"

typedef struct SysTickUptimeInfoAdapter SysTickUptimeInfoAdapter;

/**
 * @brief Adapter Interface.
 * @details Implementations of call-outs to get the platform specific up-time info time every system tick.
 */
struct SysTickUptimeInfoAdapter
{
    SpinTimerUptimeInfoAdapter super;   /*!< Base class @ref SysTickUptimeInfoAdapter. */
};

/* Function prototypes */
/**
 * @brief Constructor.
 * 
 * @return SysTickUptimeInfoAdapter* 
 */
SysTickUptimeInfoAdapter* SysTickUptimeInfoAdapter_create();

/**
 * @brief Initializer.
 * 
 * @param me Pointer to this SysTickUptimeInfoAdapter object.
 */
void SysTickUptimeInfoAdapter_init(SysTickUptimeInfoAdapter* const me);

/**
 * @brief Destructor.
 * 
 * @param me Pointer to this SysTickUptimeInfoAdapter object.
 */
void SysTickUptimeInfoAdapter_destroy(SysTickUptimeInfoAdapter* const me);

/**
 * @brief 
 * 
 * @param me Pointer to this SysTickUptimeInfoAdapter object.
 * @return uint32_t 
 */
uint32_t SysTickUptimeInfoAdapter_currentTimeMicros(SysTickUptimeInfoAdapter const* const me);

/**
 * @brief 
 * 
 * @param me Pointer to this SysTickUptimeInfoAdapter object.
 * @return uint32_t 
 */
uint32_t SysTickUptimeInfoAdapter_microsPerTick(SysTickUptimeInfoAdapter const* const me);

/**
 * @brief Update the current time count time base.
 * @details Helper function running in interrupt context. 
 */
void SysTickUptimeInfoAdapter_updateTickCount();

#endif
