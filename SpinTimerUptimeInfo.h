/*
 * SpinTimerUptimeInfo.h
 *
 *  Created on: 01.10.2013
 *      Author: niklausd
 */

#ifndef SpinTimerUptimeInfo_H_
#define SpinTimerUptimeInfo_H_

#include <stdlib.h>
#include "SpinTimerUptimeInfoAdapter.h"

typedef struct SpinTimerUptimeInfo SpinTimerUptimeInfo;
typedef struct SpinTimerUptimeInfoAttr
{
  SpinTimerUptimeInfoAdapter* adapter;
} SpinTimerUptimeInfoAttr;

/**
 * Helper class to use the appropriate time base depending on framework.
 */
struct SpinTimerUptimeInfo
{
    SpinTimerUptimeInfoAttr attr;                                                         /*!< @ref SpinTimerUptimeInfoAttr */
    void (*assignAdapter)(SpinTimerUptimeInfo* me, SpinTimerUptimeInfoAdapter* adapter);  /*!< @ref SpinTimerUptimeInfo_assignAdapter */
    SpinTimerUptimeInfoAdapter* (*adapter)(SpinTimerUptimeInfo* me);                      /*!< @ref SpinTimerUptimeInfo_adapter */
    uint32_t (*currentTimeMicros)(SpinTimerUptimeInfo const* const me);                   /*!< @ref SpinTimerUptimeInfo_currentTimeMicros */
    uint32_t (*maxTimeValue)(SpinTimerUptimeInfo const* const me);                        /*!< @ref SpinTimerUptimeInfo_maxTimeValue */
    uint32_t (*microsPerTick)(SpinTimerUptimeInfo const* const me);                       /*!< @ref SpinTimerUptimeInfo_microsPerTick */
};

SpinTimerUptimeInfo* SpinTimerUptimeInfo_instance();
void SpinTimerUptimeInfo_destroy();

/**
 * @brief Get current uptime in microseconds.
 * @param SpinTimerUptimeInfo const* const Pointer to this SpinTimerUptimeInfo object.
 * @return uint32_t current uptime [us].
 */
static inline uint32_t SpinTimerUptimeInfo_currentTimeMicros(SpinTimerUptimeInfo const* const me)
{
  uint32_t us = 0;
  if (0 != me->attr.adapter)
  {
    us = me->attr.adapter->currentTimeMicros(me->attr.adapter);
  }
  return us;
}

static inline uint32_t SpinTimerUptimeInfo_maxTimeValue(SpinTimerUptimeInfo const* const me)
{
    uint32_t max = 0;
    if (0 != me->attr.adapter)
    {
        max = me->attr.adapter->maxTimeValue(me->attr.adapter);
    }
    return max;
}

static inline uint32_t SpinTimerUptimeInfo_microsPerTick(SpinTimerUptimeInfo const* const me)
{
    uint32_t tickMicros = 0;
    if (0 != me->attr.adapter)
    {
        tickMicros = me->attr.adapter->microsPerTick(me->attr.adapter);
    }
    return tickMicros;
}

void SpinTimerUptimeInfo_assignAdapter(SpinTimerUptimeInfo* me, SpinTimerUptimeInfoAdapter* adapter);

SpinTimerUptimeInfoAdapter* SpinTimerUptimeInfo_adapter(SpinTimerUptimeInfo* me);

#endif
