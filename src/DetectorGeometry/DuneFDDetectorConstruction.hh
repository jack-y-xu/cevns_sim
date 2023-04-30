//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH
#define CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "DuneFDSensitiveDetector.hh"
#include "G4OpticalPhoton.hh"
#include "GlobalConstants.hh"

// Definitions of the box


class DuneFDDetectorConstruction: public G4VUserDetectorConstruction {
    public:
        DuneFDDetectorConstruction();
        ~DuneFDDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

    private:
        G4SDManager* sdManager;

        G4VPhysicalVolume* worldPhys;
        G4VPhysicalVolume* lArPhys;
        G4VPhysicalVolume* sdPhys;

        G4LogicalVolume* worldLog;
        G4LogicalVolume* lArLog;
        G4LogicalVolume* sdLog;

        G4VSensitiveDetector* sd;

        G4Material* getLiquidArgon();
        G4Material *getSiPM();

        void placeWorld();
        void placeArgonBox();
        void placeSensitiveDetector();

    G4Material *getAir();

    G4Material *getStainlessSteel();
};

#endif //CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH