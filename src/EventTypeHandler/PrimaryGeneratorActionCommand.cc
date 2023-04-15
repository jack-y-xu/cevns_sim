//
// Created by Jack Xu on 4/14/23.
//

#include "PrimaryGeneratorActionCommand.hh"

PrimaryGeneratorActionCommand::PrimaryGeneratorActionCommand(PrimaryGeneratorActionDispatcher* dispatcher)
        : G4UImessenger(), dispatcher(dispatcher) {
    G4UIdirectory* pgaDirectory = new G4UIdirectory("/pga/");
    pgaDirectory->SetGuidance("Control of PrimaryGeneratorActionDispatcher");

    setCurrentPGACommand = new G4UIcmdWithAString("/pga/setEventType", this);
    setCurrentPGACommand->SetGuidance("Set the current PrimaryGeneratorAction by type");
    setCurrentPGACommand->SetParameterName("primaryActionGeneratorType", false);
}

PrimaryGeneratorActionCommand::~PrimaryGeneratorActionCommand() {}

void PrimaryGeneratorActionCommand::SetNewValue(G4UIcommand* command, G4String newValue) {
    if (command == setCurrentPGACommand) {
        dispatcher->SetGeneratorType(newValue);
    }
}