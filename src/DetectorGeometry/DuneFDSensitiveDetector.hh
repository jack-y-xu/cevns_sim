//
// Created by Jack Xu on 4/21/23.
//

#ifndef CEVNS_SIM_DUNEFDSENSITIVEDETECTOR_HH
#define CEVNS_SIM_DUNEFDSENSITIVEDETECTOR_HH 1

#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class DuneFDSensitiveDetector : public G4VSensitiveDetector
{
public:
    DuneFDSensitiveDetector(const G4String& name);
    virtual ~DuneFDSensitiveDetector();

    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
};


#endif //CEVNS_SIM_DUNEFDSENSITIVEDETECTOR_HH
