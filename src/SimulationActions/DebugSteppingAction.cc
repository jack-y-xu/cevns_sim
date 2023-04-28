//
// Created by Jack Xu on 4/26/23.
//

#include "DebugSteppingAction.hh"

void DebugSteppingAction::UserSteppingAction(const G4Step* step) {
    G4Track* track = step->GetTrack();

    // Check if the track is an optical photon
    if (track->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition()) {
        // Get the endpoint position of the track
        G4StepPoint* postStepPoint = step->GetPostStepPoint();
        G4StepStatus status = postStepPoint->GetStepStatus();

        // Get the reason for the track ending
        std::string reason;
        switch (status) {
            case fWorldBoundary:
                reason = "reached the boundary of the world volume";
                break;
            case fGeomBoundary:
                reason = "reached the boundary of a geometry volume";
                break;
            case fPostStepDoItProc:
                reason = "was killed by its post-step process";
                break;
            case fUserDefinedLimit:
                reason = "exceeded a user-defined limit";
                break;
            default:
                reason = "unknown reason";
        }

        // Print the endpoint position and reason for the track ending
        G4cout << "Photon endpoint: " << postStepPoint << ", reason: " << reason << G4endl;
    }

}