//
// Created by Jack Xu on 4/21/23.
//

#include <G4RunManager.hh>
#include "DuneFDSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

DuneFDSensitiveDetector::DuneFDSensitiveDetector(const G4String& name): G4VSensitiveDetector(name)
{

}

DuneFDSensitiveDetector::~DuneFDSensitiveDetector()
{

}

G4bool DuneFDSensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history)
{
    // The below is for just making the transfer matrix information
    const G4Event* currentEvent = G4RunManager::GetRunManager()->GetCurrentEvent();
    CEvNSEventData* data = dynamic_cast<CEvNSEventData*>(currentEvent->GetUserInformation());
    data->incrementNumDetected();
    return true;


// The below is for detailed analysis
// Now you can access the current event's information as needed
// G4int eventID = currentEvent->GetEventID();
// Process the hit (energy deposition, position, etc.) and store relevant information
//    G4double edep = step->GetTotalEnergyDeposit();
//    if (edep == 0.) return false;
//
//    G4RunManager* runManager = G4RunManager::GetRunManager();
//    const G4Event* currentEvent = runManager->GetCurrentEvent();
//    G4int eventNumber = currentEvent->GetEventID();
//
//
//    // Get the analysis manager
//    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
//
//    // Fill the energy deposit histogram
//    analysisManager->FillH1(0, edep);
//
//    // Get the position of the hit
//    G4ThreeVector position = step->GetPreStepPoint()->GetPosition();
//
//    // Fill the ntuple with the hit information
//    analysisManager->FillNtupleDColumn(0, edep);
//    analysisManager->FillNtupleDColumn(1, position.x());
//    analysisManager->FillNtupleDColumn(2, position.y());
//    analysisManager->FillNtupleDColumn(3, position.z());
//    analysisManager->FillNtupleDColumn(4, eventNumber);
//    analysisManager->FillNtupleDColumn(5, (int(eventNumber)/1000)+1);
//    analysisManager->AddNtupleRow();
//
//    return true;

}