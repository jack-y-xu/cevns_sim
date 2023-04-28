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
#include "PrimaryGeneratorActionCommand.hh"
#include "DebugRunAction.hh"
#include "DebugSteppingAction.hh"
#include "DefaultRunAction.hh"


class InstanceManager {
    G4RunManager* runManager = nullptr;
    G4VisManager* visManager = nullptr;
    G4UImanager* UIManager = nullptr;
    G4UIExecutive* ui = nullptr;
    PrimaryGeneratorActionDispatcher* primaryGeneratorActionDispatcher = nullptr;

public:
    InstanceManager(int argc, char** argv) {
        initializeUI(argc, argv);
        setupRandom();

        setupPrecision(4);
        initializeRunManager();
        initializeUIManager();
        startUI();
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
        G4cout << "init runaction called" << G4endl;
        runManager->SetUserAction(new DefaultRunAction);
    }

    void initializeUI(int argc, char** argv) {
        ui = new G4UIExecutive(argc, argv);
    }

    void initializeUIManager() {
        UIManager = G4UImanager::GetUIpointer();

        PrimaryGeneratorActionCommand* pgaCommand = new PrimaryGeneratorActionCommand(primaryGeneratorActionDispatcher);

        initializeVisManager();
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

    InstanceManager* im = new InstanceManager(argc, argv);

}
