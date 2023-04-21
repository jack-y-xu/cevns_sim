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
    // Implement your custom hit processing logic here
    return true;
}