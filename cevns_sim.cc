//
// Created by Jack Xu on 4/14/23.
//

#include "G4RunManager.hh"
#include "G4UIManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4SteppingVerbose.hh"
#include "Randomize.hh"

#include "DuneFDDetectorConstruction.hh"
#include "CombinedPhysicsList.hh"
#include "PrimaryGeneratorActionDispatcher.hh"
#include "src/Commands/PrimaryGeneratorActionCommand.hh"
#include "DebugRunAction.hh"
#include "DebugSteppingAction.hh"
#include "DefaultRunAction.hh"
#include "CEvNSEventAction.hh"
#include "WriteRecordingCommand.hh"
#include "CEvNSPrimaryGeneratorAction.hh"

class InstanceManager {
public:
    G4RunManager* runManager = nullptr;
    G4VisManager* visManager = nullptr;
    G4UImanager* UIManager = nullptr;
    G4UIExecutive* ui = nullptr;
    CEvNSEventAction* eventAction = nullptr;
    CEvNSPrimaryGeneratorAction* pga = nullptr;
    PrimaryGeneratorActionDispatcher* primaryGeneratorActionDispatcher = nullptr;

    InstanceManager(int argc, char** argv, bool visual) {
        setupRandom();
        setupPrecision(4);
        initializeRunManager();
        initializeUIManager(visual);

        if (visual) {
            initializeUI(argc, argv);
            initializeVisManager();
            startUI();
        }

    }

    ~InstanceManager() {
        if (ui) delete ui;
        if (UIManager) delete UIManager;
        if (visManager) delete visManager;
        if (runManager) delete runManager;
    }

    void setupRandom() {
        CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
    }

    void setupPrecision(int _precision) {
        G4int precision = _precision;
        G4SteppingVerbose::UseBestUnit(precision);
    }

    void initializeRunManager() {
        runManager = new G4RunManager;

        // initialization classes
        runManager->SetUserInitialization(new DuneFDDetectorConstruction);
        runManager->SetUserInitialization(new CombinedPhysicsList);

        primaryGeneratorActionDispatcher = new PrimaryGeneratorActionDispatcher();
        runManager->SetUserAction(primaryGeneratorActionDispatcher);

        pga = dynamic_cast<CEvNSPrimaryGeneratorAction*>(primaryGeneratorActionDispatcher->getCurrentPGA());

        eventAction = new CEvNSEventAction("output.root");
        runManager->SetUserAction(eventAction);
    }

    void initializeUI(int argc, char** argv) {
        ui = new G4UIExecutive(argc, argv);
    }

    void initializeUIManager(bool visual) {
        UIManager = G4UImanager::GetUIpointer();

        PrimaryGeneratorActionCommand* pgaCommand = new PrimaryGeneratorActionCommand(primaryGeneratorActionDispatcher);
        WriteRecordingCommand* recordCommand = new WriteRecordingCommand(eventAction);

        UIManager->ApplyCommand("/control/execute vis.mac");
    }

    void startUI() {
        ui->SessionStart();
    }

    void initializeVisManager() {
        visManager = new G4VisExecutive;
        visManager->Initialize();
    }
};

int main(int argc, char** argv) {

    InstanceManager* im = new InstanceManager(argc, argv, false);

    for (int numPhotons = 1; numPhotons <= 40; numPhotons ++) {
        im->pga->setNumPhotons(numPhotons);
        im->UIManager->ApplyCommand("/run/beamOn 10000");
        G4cout << "Finished " << numPhotons << '\n';
    }

    im->eventAction->writeRecording();
}
