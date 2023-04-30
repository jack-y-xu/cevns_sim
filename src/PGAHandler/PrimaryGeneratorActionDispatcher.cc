//
// Created by Jack Xu on 4/14/23.
//

#include "PrimaryGeneratorActionDispatcher.hh"

void PrimaryGeneratorActionDispatcher::initializePGAs() {
    cEvNSPrimaryGeneratorAction = new CEvNSPrimaryGeneratorAction();
    nameToPGAMap["cevns"] = cEvNSPrimaryGeneratorAction;

    // NEEDS TO INITIALIZE OTHER ONES AS WELL

    currentPrimaryGeneratorAction = cEvNSPrimaryGeneratorAction;
}

void PrimaryGeneratorActionDispatcher::setCurrentPGA(G4String generatorType) {
    if (nameToPGAMap.find(generatorType) != nameToPGAMap.end())
        this->currentPrimaryGeneratorAction = nameToPGAMap[generatorType];
    else {
        G4cerr << "Invalid generator type " + generatorType << G4endl;
    }
}

PrimaryGeneratorActionDispatcher::PrimaryGeneratorActionDispatcher() {
    initializePGAs();
}

G4VUserPrimaryGeneratorAction* PrimaryGeneratorActionDispatcher::getCurrentPGA() {
    return currentPrimaryGeneratorAction;
}

PrimaryGeneratorActionDispatcher::~PrimaryGeneratorActionDispatcher() {}

void PrimaryGeneratorActionDispatcher::GeneratePrimaries(G4Event* event) {
    this->currentPrimaryGeneratorAction->GeneratePrimaries(event);
}

void PrimaryGeneratorActionDispatcher::SetGeneratorType(G4String generatorType) {
    setCurrentPGA(generatorType);
}