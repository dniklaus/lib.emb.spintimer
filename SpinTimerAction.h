#ifndef __SpinTimerAction_H
#define __SpinTimerAction_H

typedef struct SpinTimerAction SpinTimerAction;

/**
 * @brief Action Interface, will notify time expired event.
 * @details Implementations derived from this interface can be injected into a SpinTimer object.
 * The Timer then will call out the specific action's timeExpired() method.
 */
struct SpinTimerAction
{
    struct SpinTimerActionVtable const* vptr;               /*!< virtual pointer */
    void (*timeExpired)(SpinTimerAction const* const me);   /*!< Time expired event. To be implemented by specific Timer Action class (pure virtual). */
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
