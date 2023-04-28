//
// Created by Jack Xu on 4/21/23.
//

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
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;

    // Get the analysis manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    // Fill the energy deposit histogram
    analysisManager->FillH1(0, edep);

    // Get the position of the hit
    G4ThreeVector position = step->GetPreStepPoint()->GetPosition();

    // Fill the ntuple with the hit information
    analysisManager->FillNtupleDColumn(0, edep);
    analysisManager->FillNtupleDColumn(1, position.x());
    analysisManager->FillNtupleDColumn(2, position.y());
    analysisManager->FillNtupleDColumn(3, position.z());
    analysisManager->AddNtupleRow();

    return true;
}