//
// Created by Jack Xu on 4/26/23.
//

#include "DebugRunAction.hh"

DebugRunAction::DebugRunAction() : G4UserRunAction() {}
DebugRunAction::~DebugRunAction() {}

void DebugRunAction::EndOfRunAction(const G4Run* run) {
    G4cout << "EndOfRunAction() called" << G4endl;
    // Get the track container from the tracking manager
    std::vector<G4Track*>* trackVector = G4EventManager::GetEventManager()->GetTrackingManager()->GimmeSecondaries();
    G4cout << trackVector->size() << std::endl;

    // Loop over all the steps taken by all the tracks in the simulation
    for (G4int i = 0; i < trackVector->size(); ++i) {
        G4Track* track = (*trackVector)[i];

        // Check if the track is still active (i.e. not stopped or killed)
        if (track && track->GetTrackStatus() == fAlive) {
            // Loop over all the steps taken by the track

            G4StepPoint* preStepPoint = nullptr;
            G4StepPoint* postStepPoint = nullptr;

            for (G4int j = 0; j < track->GetCurrentStepNumber(); ++j) {
                const G4Step* step = track->GetStep();
//                const G4Step* step = track->GetStep();
                preStepPoint = step->GetPreStepPoint();
                postStepPoint = step->GetPostStepPoint();

                // Print out information about the step
                G4cout << "Step #" << j << ": "
                       << "Particle: " << track->GetDynamicParticle()->GetDefinition()->GetParticleName() << ", "
                       << "Position: (" << preStepPoint->GetPosition().x() << ", "
                       << preStepPoint->GetPosition().y() << ", "
                       << preStepPoint->GetPosition().z() << ") -> ("
                       << postStepPoint->GetPosition().x() << ", "
                       << postStepPoint->GetPosition().y() << ", "
                       << postStepPoint->GetPosition().z() << "), "
                       << "Volume: " << preStepPoint->GetPhysicalVolume()->GetName() << ", "
                       << "Energy: " << preStepPoint->GetKineticEnergy() << " -> " << postStepPoint->GetKineticEnergy() << ", "
                       << "Step length: " << step->GetStepLength() << G4endl;
                track->IncrementCurrentStepNumber();
            }
        }
    }
}