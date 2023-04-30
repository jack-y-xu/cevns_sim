//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_CEVNSPRIMARYGENERATORACTION_HH
#define CEVNS_SIM_CEVNSPRIMARYGENERATORACTION_HH 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4ParticleTable.hh"
#include "G4ThreeVector.hh"
#include "G4PrimaryVertex.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4RandomDirection.hh"
#include "DuneFDDetectorConstruction.hh"
#include "CEvNSPrimaryGeneratorAction.hh"
#include "CEvNSEventData.hh"

class G4Event;
class CEvNSEventData;

class CEvNSPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {
public:
    CEvNSPrimaryGeneratorAction();
    ~CEvNSPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);
    void setNumPhotons(G4int numPhotons);

private:

    G4ParticleTable* particleTable;
    G4double sampleEventTime();
    G4int sampleNumPhotons();
    G4double samplePhotonEnergy();
    G4ThreeVector samplePhotonDirection();
    G4ThreeVector getPerpPolarizationDirection(G4ThreeVector momentumDirection);
    G4ThreeVector sampleEventPosition();
    G4ParticleDefinition* opticalPhotonDefinition;
    G4ParticleDefinition* getOpticalPhotonDefinition();

    G4int sampleNumPhotons(G4Event *event);
    G4int numPhotons = -1;
    CEvNSEventData* data;
};


#endif //CEVNS_SIM_CEVNSPRIMARYGENERATORACTION_HH
