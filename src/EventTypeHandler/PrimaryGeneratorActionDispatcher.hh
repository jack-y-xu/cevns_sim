//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_PRIMARYGENERATORACTIONDISPATCHER_HH
#define CEVNS_SIM_PRIMARYGENERATORACTIONDISPATCHER_HH 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "CEvNSPrimaryGeneratorAction.hh"
#include "G4ExceptionSeverity.hh"
#include "G4Exception.hh"
#include "globals.hh"

class PrimaryGeneratorActionDispatcher: public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorActionDispatcher();
    ~PrimaryGeneratorActionDispatcher();
public: //
    virtual void GeneratePrimaries(G4Event* anEvent);
    void SetGeneratorType(G4String generatorType);
private:
    void initializePGAs();
    void setCurrentPGA(G4String generatorType);
//    RadioactiveDecayPrimaryGeneratorAction* radioactiveAction;
    CEvNSPrimaryGeneratorAction* cEvNSPrimaryGeneratorAction;
//    ChargedCurrentNeutrinoPrimaryGeneratorAction* fChargedCurrentNeutrinoGeneratorAction;
//    BackgroundPrimaryGeneratorAction* fBackgroundPrimaryGeneratorAction;
    G4VUserPrimaryGeneratorAction* currentPrimaryGeneratorAction;

    std::map<G4String, G4VUserPrimaryGeneratorAction*> nameToPGAMap;
};


#endif //CEVNS_SIM_PRIMARYGENERATORACTIONDISPATCHER_HH
