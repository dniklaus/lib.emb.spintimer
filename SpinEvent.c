

#include <stdlib.h>
#include <assert.h>
#include "SpinTimer.h"
#include "SpinEvent.h"

// local function
static void SpinEvent_received(SpinEvent* const me);

SpinEvent* SpinEvent_create()
{
    SpinEvent* me = malloc(sizeof(SpinEvent));
    SpinEvent_init(me);
    return me;
}

void SpinEvent_init(SpinEvent* me)
{
    static const SpinEventVtable evtVtable = {
        &SpinEvent_received
    };
    me->vptr = &evtVtable;
    me->received = &SpinEvent_received_vcall;

    static const SpinTimerActionVtable timerVtable = {
        (void (*)(SpinTimerAction const* const me))&SpinEvent_timeExpired
    };
    SpinTimerAction_init(&me->super);
    me->super.vptr = &timerVtable;

    me->send = &SpinEvent_send;

    me->attr.timer  = SpinTimer_create(SpinTimerMode_oneShot);
    me->attr.timer->assignAction(me->attr.timer, (SpinTimerAction*)me);
}

void SpinEvent_destroy(SpinEvent* me)
{

    SpinEvent_finalize(me);
    free(me);
}

void SpinEvent_finalize(SpinEvent* me)
{
    (void)me;
}

void SpinEvent_send(SpinEvent* const me)
{
    me->attr.timer->start(me->attr.timer, 0);
}

void SpinEvent_timeExpired(SpinEvent* me)
{
    me->received(me);
}

void SpinEvent_received(SpinEvent* const me)
{
    (void)me;
    assert(0);
}
