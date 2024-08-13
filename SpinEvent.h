#ifndef _SpinEvent_H
#define _SpinEvent_H

#include "SpinTimerAction.h"

typedef struct SpinTimer SpinTimer;

typedef struct SpinEvent SpinEvent;
typedef struct SpinEventVtable SpinEventVtable;
typedef struct SpinEventAttr 
{
    SpinTimer* timer;
} SpinEventAttr;

struct SpinEvent
{
    SpinTimerAction super;
    SpinEventVtable const* vptr;
    SpinEventAttr attr;
    void (*send)(SpinEvent* const me);
    void (*received)(SpinEvent* const me);  /* pure virtual */
};

struct SpinEventVtable
{
    void (*received)(SpinEvent* const me);
};

SpinEvent* SpinEvent_create();
void SpinEvent_init(SpinEvent* const me);
void SpinEvent_destroy(SpinEvent* me);
void SpinEvent_finalize(SpinEvent* me);

void SpinEvent_send(SpinEvent* const me);

void SpinEvent_timeExpired(SpinEvent* const me);

static inline void SpinEvent_received_vcall(SpinEvent* const me)
{
    (*me->vptr->received)(me);
}

#endif
