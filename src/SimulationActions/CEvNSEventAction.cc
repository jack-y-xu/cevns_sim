//
// Created by Jack Xu on 4/28/23.
//

#include "CEvNSEventAction.hh"

CEvNSEventAction::CEvNSEventAction(const std::string& filepath) : G4UserEventAction() {
    analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);


    // Create a histogram for the energy deposit
//    analysisManager->CreateH1("detection", "Number of photons detected", 100, 0., 20*eV);
//
    // Create an ntuple to store each event's number of detections:
    analysisManager->CreateNtuple("detections", "Number of photons detected vs generated");
    analysisManager->CreateNtupleDColumn("numCreated");
    analysisManager->CreateNtupleDColumn("numDetected");
    analysisManager->CreateNtupleDColumn("vertexX");
    analysisManager->CreateNtupleDColumn("vertexY");
    analysisManager->CreateNtupleDColumn("vertexZ");
    analysisManager->FinishNtuple();

    analysisManager->SetFileName(filepath);
    // Open the output file
    analysisManager->OpenFile();
}
CEvNSEventAction::~CEvNSEventAction() {}

void CEvNSEventAction::writeRecording() {
    analysisManager->Write();
    analysisManager->CloseFile();
}

void CEvNSEventAction::BeginOfEventAction(const G4Event* event) {
    //    G4cout << "-----------------------------\nEventActionBegin\n";
}

void CEvNSEventAction::EndOfEventAction(const G4Event* event) {

    // retrieve user-defined data structure from event
    CEvNSEventData* data = dynamic_cast<CEvNSEventData*>(G4EventManager::GetEventManager()->GetUserInformation());

//    G4cout << "Event ID: " << event->GetEventID() << '\n'
//           << "Event num photons: " << data->getNumCreatedPhotons() << '\n'
//           << "Number of photons at detector: " << data->getNumDetected() << '\n'
//           << "Origin: " << data->getOrigin() << '\n'
//           << "Time of event: " << data->getTime() << '\n';

    // Fill the energy deposit histogram

    // Get the position of the hit
    G4ThreeVector vertex = data->getOrigin();

    // Fill the ntuple with the hit information
    analysisManager->FillNtupleDColumn(0, data->getNumCreatedPhotons());
    analysisManager->FillNtupleDColumn(1, data->getNumDetected());
    analysisManager->FillNtupleDColumn(2, vertex.x());
    analysisManager->FillNtupleDColumn(3, vertex.y());
    analysisManager->FillNtupleDColumn(4, vertex.z());
    analysisManager->AddNtupleRow();

//
//    // do something with extra information
//    G4double energyDeposited = cevnsData->GetEnergyDeposited();
//    G4double recoilEnergy = cevnsData->GetRecoilEnergy();
//    // ...
//
//    // delete user-defined data structure
//    delete cevnsData;
//    G4cout<< "------------------------------\nEventActionEnd\n";
}