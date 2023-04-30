//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_PRIMARYGENERATORACTIONCOMMAND_HH
#define CEVNS_SIM_PRIMARYGENERATORACTIONCOMMAND_HH 1

#include "G4UIcommand.hh"
#include "G4UImessenger.hh"
#include "PrimaryGeneratorActionDispatcher.hh"
#include "G4UIcmdWithAString.hh"

class PrimaryGeneratorActionCommand : public G4UImessenger {
public:
    PrimaryGeneratorActionCommand(PrimaryGeneratorActionDispatcher* dispatcher);
    virtual ~PrimaryGeneratorActionCommand();

    virtual void SetNewValue(G4UIcommand* command, G4String newValue);

private:
    PrimaryGeneratorActionDispatcher* dispatcher;
    G4UIcmdWithAString* setCurrentPGACommand;
};

#endif //CEVNS_SIM_PRIMARYGENERATORACTIONCOMMAND_HH
