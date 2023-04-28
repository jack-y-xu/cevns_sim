//
// Created by Jack Xu on 4/26/23.
//

#ifndef CEVNS_SIM_DEBUGSTEPPINGACTION_HH
#define CEVNS_SIM_DEBUGSTEPPINGACTION_HH


#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4TrackingManager.hh"

class DebugSteppingAction: public G4UserSteppingAction {

public:
    virtual void UserSteppingAction(const G4Step* step);
};


#endif //CEVNS_SIM_DEBUGSTEPPINGACTION_HH
