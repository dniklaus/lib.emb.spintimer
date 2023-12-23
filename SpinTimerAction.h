#ifndef __SpinTimerAction_H
#define __SpinTimerAction_H

typedef struct SpinTimerAction SpinTimerAction;
typedef struct SpinTimerActionVtable SpinTimerActionVtable;

/**
 * @brief Action Interface, will notify time expired event.
 * @details Implementations derived from this interface can be injected into a SpinTimer object.
 * The Timer then will call out the specific action's timeExpired() method.
 */
struct SpinTimerAction
{
    SpinTimerActionVtable const* vptr;               /*!< virtual pointer */
    
    /**
     * @brief SpinTimer object's expiry action.
     * @details Implementation of this will be called on the SpinTimer object's expiry when injected. Pure virtual function. 
     * @param me Pointer to this timer action object.
     */
    void (*timeExpired)(SpinTimerAction const* const me);   
};

struct SpinTimerActionVtable
{
    void (*timeExpired)(SpinTimerAction const* const me);
};

/* SpinTimerAction's operations... */
SpinTimerAction* SpinTimerAction_create();
void SpinTimerAction_init(SpinTimerAction* const me);
void SpinTimerAction_destroy(SpinTimerAction* me);

/* virtual calls (late binding) */
static inline void SpinTimerAction_timeExpired_vcall(SpinTimerAction const* const me)
{
    (*me->vptr->timeExpired)(me);
}

#endif
