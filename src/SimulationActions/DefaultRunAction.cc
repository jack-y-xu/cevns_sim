//
// Created by Jack Xu on 4/27/23.
//

#include "DefaultRunAction.hh"


DefaultRunAction::DefaultRunAction() {

    analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);

    // Create a histogram for the energy deposit
//    analysisManager->CreateH1("energyDeposit", "Energy deposit", 100, 0., 20*eV);

    // Create an ntuple to store the energy deposit and x, y, z position
    analysisManager->CreateNtuple("hits", "Energy Deposit and Position");
    analysisManager->CreateNtupleDColumn("energyDeposit");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("z");
    analysisManager->FinishNtuple();
};

DefaultRunAction::~DefaultRunAction() {};

void DefaultRunAction::BeginOfRunAction(const G4Run *) {
    analysisManager->SetFileName("output");
    // Open the output file
    analysisManager->OpenFile();
}


void DefaultRunAction::EndOfRunAction(const G4Run *) {
    analysisManager->Write();
    analysisManager->CloseFile();
}



