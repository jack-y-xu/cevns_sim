//
// Created by Jack Xu on 4/28/23.
//

#ifndef CEVNS_SIM_CEVNSEVENTACTION_HH
#define CEVNS_SIM_CEVNSEVENTACTION_HH 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4EventManager.hh"
#include "G4VUserEventInformation.hh"
#include "CEvNSEventData.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

class CEvNSEventAction : public G4UserEventAction {
public:
    CEvNSEventAction(const std::string &filepath);
    virtual ~CEvNSEventAction();

    void writeRecording();

    virtual void BeginOfEventAction(const G4Event* event) override;

    virtual void EndOfEventAction(const G4Event* event) override;

private:
    G4AnalysisManager* analysisManager;
};


#endif //CEVNS_SIM_CEVNSEVENTACTION_HH
