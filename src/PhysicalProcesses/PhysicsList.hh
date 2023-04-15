//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_PHYSICSLIST_HH
#define CEVNS_SIM_PHYSICSLIST_HH 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class PhysicsList: public G4VUserPhysicsList {
public:
    PhysicsList();
    ~PhysicsList();

protected:
    virtual void ConstructParticle();
    virtual void ConstructProcess();
    virtual void SetCuts();
};

#endif //CEVNS_SIM_PHYSICSLIST_HH
