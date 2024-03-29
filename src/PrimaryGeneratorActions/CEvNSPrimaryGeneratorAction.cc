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
    data = new CEvNSEventData();

    G4int numPhotons = sampleNumPhotons(event);
    data->setNumCreatedPhotons(numPhotons);
    G4double eventTime = sampleEventTime();
    data->setTime(eventTime);

    const G4ThreeVector eventPosition = sampleEventPosition();
    data->setOrigin(eventPosition);

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

    event->SetUserInformation(data);
}

// NOT IMPLEMENTED YET
G4double CEvNSPrimaryGeneratorAction::sampleEventTime() {
    return 0 * s;
};

G4int CEvNSPrimaryGeneratorAction::sampleNumPhotons(G4Event* event) {
//    return (int(event->GetEventID())/10000)+1;
//    return int(1.0 + 30*G4UniformRand());
    if (numPhotons != -1) return numPhotons;
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
    G4double x = (G4UniformRand()-0.5) * ARGON_SLAB_X;
    G4double y = (G4UniformRand()-0.5) * ARGON_SLAB_Y;
    G4double z = (G4UniformRand()-0.5) * ARGON_SLAB_Z;
    return G4ThreeVector(x,y,z);
};

G4ParticleDefinition* CEvNSPrimaryGeneratorAction::getOpticalPhotonDefinition() {
    G4ParticleDefinition* opticalPhoton = G4OpticalPhoton::Definition();
    return opticalPhoton;
};

void CEvNSPrimaryGeneratorAction::setNumPhotons(G4int pNumPhotons) {
    numPhotons = pNumPhotons;
}