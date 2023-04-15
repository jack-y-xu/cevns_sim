//
// Created by Jack Xu on 4/14/23.
//

#include "CEvNSPrimaryGeneratorAction.hh"

CEvNSPrimaryGeneratorAction::CEvNSPrimaryGeneratorAction(): G4VUserPrimaryGeneratorAction() {
    particleTable = G4ParticleTable::GetParticleTable();
    opticalPhotonDefinition = getOpticalPhotonDefinition();
}

CEvNSPrimaryGeneratorAction::~CEvNSPrimaryGeneratorAction() {

}

void CEvNSPrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    G4int numPhotons = sampleNumPhotons();

    G4double eventTime = sampleEventTime();
    G4ThreeVector eventPosition = sampleEventPosition();
    G4PrimaryVertex* vertex = new G4PrimaryVertex(eventPosition, eventTime);

    for (int i = 0; i < numPhotons; i++) {
        G4PrimaryParticle* particle = new G4PrimaryParticle(opticalPhotonDefinition);

        G4ThreeVector photonDirection = samplePhotonDirection();
        G4ThreeVector photonPolarizationDirection = getPerpPolarizationDirection(photonDirection);
        G4double photonKineticEnergy = samplePhotonEnergy();

        particle->SetMomentumDirection(photonDirection);
        particle->SetPolarization(photonPolarizationDirection);
        particle->SetKineticEnergy(photonKineticEnergy);

        vertex->SetPrimary(particle);
    }
    event->AddPrimaryVertex(vertex);
}


// NOT IMPLEMENTED YET
G4double CEvNSPrimaryGeneratorAction::sampleEventTime() {
    return 0 * s;
};

G4int CEvNSPrimaryGeneratorAction::sampleNumPhotons() {
    return 30;
};

G4double CEvNSPrimaryGeneratorAction::samplePhotonEnergy() {
    G4double energy_123nm = 9.32 * eV;
    G4double energy_133nm = 10.08 * eV;
    G4double particleEnergy = G4RandFlat::shoot(energy_133nm, energy_123nm);
    return particleEnergy;
};

G4ThreeVector CEvNSPrimaryGeneratorAction::samplePhotonDirection() {
    return G4RandomDirection();
};

G4ThreeVector CEvNSPrimaryGeneratorAction::getPerpPolarizationDirection(G4ThreeVector momentumDirection) {
    G4ThreeVector orthogonalVector = G4ThreeVector(1.0, 0.0, 0.0);
    G4ThreeVector polarizationDirection = momentumDirection.cross(orthogonalVector);
    if (polarizationDirection.mag() < 1e-9) {
        orthogonalVector = G4ThreeVector(0.0, 1.0, 0.0);
        polarizationDirection = momentumDirection.cross(orthogonalVector);
    }
    polarizationDirection = polarizationDirection.unit();
    return polarizationDirection;
};

G4ThreeVector CEvNSPrimaryGeneratorAction::sampleEventPosition() {
    return G4ThreeVector(0*m,0*m,0*m);
};

G4ParticleDefinition* CEvNSPrimaryGeneratorAction::getOpticalPhotonDefinition() {
    return particleTable->FindParticle("geantino");
};