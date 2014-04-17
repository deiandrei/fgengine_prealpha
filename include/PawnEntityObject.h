#ifndef PAWNENTITYOBJECT_H_INCLUDED
#define PAWNENTITYOBJECT_H_INCLUDED
#include "VisibleObject.h"
class PawnEntityObject : public VisibleObject {
    public:
        PawnEntityObject();
        ~PawnEntityObject();
        void Update(float dT);
};


#endif // PAWNENTITYOBJECT_H_INCLUDED
