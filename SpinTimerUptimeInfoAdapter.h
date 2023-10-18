/*
 * SpinTimerUptimeInfoAdapter.h
 *
 *  Created on: 20.09.2023
 *      Author: dniklaus
 */

#ifndef SpinTimerUptimeInfoAdapter_H_
#define SpinTimerUptimeInfoAdapter_H_

#include <stdint.h>

typedef struct SpinTimerUptimeInfoAdapter SpinTimerUptimeInfoAdapter;
typedef struct SpinTimerUptimeInfoAdapterVtable SpinTimerUptimeInfoAdapterVtable;               

/**
 * @brief Adapter Interface.
 * @details This will call-out to get the platform specific up-time info time attributes in microseconds.
 */
struct SpinTimerUptimeInfoAdapter
{
    SpinTimerUptimeInfoAdapterVtable const* vptr;   /*!< SpinTimerUptimeInfoAdapter's pointer to immutable virtual function table */
    uint32_t (*currentTimeMicros)(SpinTimerUptimeInfoAdapter const* const me);  /*!< interface function currentTimeMicros() (pure virtual) */
    uint32_t (*maxTimeValue)(SpinTimerUptimeInfoAdapter const* const me);       /*!< interface function maxTimeValue() (pure virtual) */
    uint32_t (*microsPerTick)(SpinTimerUptimeInfoAdapter const* const me);      /*!< interface function microsPerTick() (pure virtual) */
};

/* SpinTimerUptimeInfoAdapter's virtual function table */
struct SpinTimerUptimeInfoAdapterVtable
{
    uint32_t (*currentTimeMicros)(SpinTimerUptimeInfoAdapter const* const me);  /*!< pointer to virtual function currentTimeMicros() */
    uint32_t (*maxTimeValue)(SpinTimerUptimeInfoAdapter const* const me);       /*!< pointer to virtual function maxTimeValue() */
    uint32_t (*microsPerTick)(SpinTimerUptimeInfoAdapter const* const me);      /*!< pointer to virtual function microsPerTick() */
};

/* Function prototypes */
/**
 * @brief Initializer.
 * @details Initializes the SpinTimerUptimeInfoAdapter object. To be called by SpinTimerUptimeInfoAdapter implementations' initializers.
 * @param me Pointer to this SpinTimerUptimeInfoAdapter object.
 */
void SpinTimerUptimeInfoAdapter_init(SpinTimerUptimeInfoAdapter* const me);

/* inline virtual calls */
static inline uint32_t SpinTimerUptimeInfoAdapter_currentTimeMicros_vcall(SpinTimerUptimeInfoAdapter const* const me)
{
    return (*me->vptr->currentTimeMicros)(me); /* late binding: calls the function in the current virtual table */
}

static inline uint32_t SpinTimerUptimeInfoAdapter_maxTimeValue_vcall(SpinTimerUptimeInfoAdapter const* const me)
{
    return (*me->vptr->maxTimeValue)(me); /* late binding: calls the function in the current virtual table */
}

static inline uint32_t SpinTimerUptimeInfoAdapter_microsPerTick_vcall(SpinTimerUptimeInfoAdapter const* const me)
{
    return (*me->vptr->microsPerTick)(me); /* late binding: calls the function in the current virtual table */
}


#endif
