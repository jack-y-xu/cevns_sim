//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_COMBINEDPHYSICSLIST_HH
#define CEVNS_SIM_COMBINEDPHYSICSLIST_HH 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"
#include "G4VModularPhysicsList.hh"
#include "G4ParticleTypes.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpBoundaryProcess.hh"
#include "CustomOpticalPhysics.hh"

class CombinedPhysicsList: public G4VModularPhysicsList {
public:
    CombinedPhysicsList();
    ~CombinedPhysicsList();

protected:
//    virtual void ConstructParticle();
//    virtual void ConstructProcess();
//    virtual void SetCuts();

};

#endif //CEVNS_SIM_COMBINEDPHYSICSLIST_HH
