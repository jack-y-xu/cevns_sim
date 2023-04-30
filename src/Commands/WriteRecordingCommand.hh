

#ifndef CEVNS_SIM_WRITERECORDING_HH
#define CEVNS_SIM_WRITERECORDING_HH 1

#include "G4UImessenger.hh"
#include "CEvNSEventAction.hh"
#include "G4UIcommand.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"

class WriteRecordingCommand : public G4UImessenger
{
public:
    WriteRecordingCommand(CEvNSEventAction* eventAction);
    virtual ~WriteRecordingCommand();

    virtual void SetNewValue(G4UIcommand* command, G4String newValue);

private:
    CEvNSEventAction* fEventAction;
    G4UIcommand* fSaveDataCmd;
};

#endif //CEVNS_SIM_WRITERECORDING_HH
