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

class G4Event;


class CEvNSPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {
public:
    CEvNSPrimaryGeneratorAction();
    ~CEvNSPrimaryGeneratorAction();

public:
    virtual void GeneratePrimaries(G4Event*);

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
};


#endif //CEVNS_SIM_CEVNSPRIMARYGENERATORACTION_HH
