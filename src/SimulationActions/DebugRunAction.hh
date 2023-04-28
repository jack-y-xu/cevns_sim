//
// Created by Jack Xu on 4/26/23.
//

#ifndef CEVNS_SIM_DEBUGRUNACTION_HH
#define CEVNS_SIM_DEBUGRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4EventManager.hh"
#include "G4TrackingManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4StepPoint.hh"


class DebugRunAction: public G4UserRunAction {
public:
    DebugRunAction();
    virtual ~DebugRunAction();

    virtual void EndOfRunAction(const G4Run*) override;
};


#endif //CEVNS_SIM_DEBUGRUNACTION_HH
