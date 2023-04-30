//
// Created by Jack Xu on 4/29/23.
//

#include "WriteRecordingCommand.hh"

WriteRecordingCommand::WriteRecordingCommand(CEvNSEventAction* eventAction)
        : G4UImessenger(),
          fEventAction(eventAction)
{
    fSaveDataCmd = new G4UIcmdWithoutParameter("/recording/write", this);
    fSaveDataCmd->SetGuidance("Trigger the writeRecording() function in CEvNSEventAction");
    fSaveDataCmd->AvailableForStates(G4State_Idle);
}

WriteRecordingCommand::~WriteRecordingCommand()
{
    delete fSaveDataCmd;
}

void WriteRecordingCommand::SetNewValue(G4UIcommand* command, G4String newValue)
{
    if (command == fSaveDataCmd)
    {
        fEventAction->writeRecording();
    }
}
