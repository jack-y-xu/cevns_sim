//
// Created by Jack Xu on 4/27/23.
//

#ifndef CEVNS_SIM_DEFAULTRUNACTION_HH
#define CEVNS_SIM_DEFAULTRUNACTION_HH 1

#include "G4Accumulable.hh"
#include "G4RunManager.hh"
#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4AnalysisManager.hh"

class DefaultRunAction : public G4UserRunAction {
public:
    DefaultRunAction();
    virtual ~DefaultRunAction();

public:

    virtual void BeginOfRunAction(const G4Run *);
    virtual void EndOfRunAction(const G4Run *);

private:
    G4VUserDetectorConstruction* detector;
    G4VUserPrimaryGeneratorAction* pga;
    G4Run* run;
    G4AnalysisManager* analysisManager;
};


#endif //CEVNS_SIM_DEFAULTRUNACTION_HH
