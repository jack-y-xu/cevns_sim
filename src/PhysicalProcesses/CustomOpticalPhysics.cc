//
// Created by Jack Xu on 4/26/23.
//

#include "CustomOpticalPhysics.hh"

CustomOpticalPhysics::CustomOpticalPhysics() : G4OpticalPhysics() {}

CustomOpticalPhysics::~CustomOpticalPhysics() {}

void CustomOpticalPhysics::ConstructProcess() {
    G4OpticalPhysics::ConstructProcess();
//
//    // Activate the desired processes
//    G4ProcessManager* pManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
    SetVerboseLevel(2);
    LogActiveProcesses();
}

void CustomOpticalPhysics::LogActiveProcesses() {
    G4ProcessManager* pManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
    G4ProcessVector* processVector = pManager->GetProcessList();

    G4cout << "Active processes for G4OpticalPhoton:" << G4endl;
    for (G4int i = 0; i < processVector->length(); ++i) {
        G4VProcess* process = (*processVector)[i];
        G4String processName = process->GetProcessName();
        G4bool isActive = (pManager->GetProcessIndex(process) != -1);

        G4cout << "  " << processName << ": " << (isActive ? "active" : "inactive") << G4endl;
    }
}

void CustomOpticalPhysics::SetVerboseLevel(G4int level) {
    // Set verbose level for optical processes
    G4ProcessManager* pManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
    G4ProcessVector* processVector = pManager->GetProcessList();

    for (G4int i = 0; i < processVector->length(); ++i) {
        G4VProcess* process = (*processVector)[i];
        process->SetVerboseLevel(level);
    }
}