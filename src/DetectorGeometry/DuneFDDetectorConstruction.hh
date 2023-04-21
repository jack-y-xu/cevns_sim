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

// Definitions of the box
#define ARGON_SLAB_X (3.6 * m)
#define ARGON_SLAB_Y (12.0 * m)
#define ARGON_SLAB_Z (58.0 * m)
#define SD_THICKNESS (0.01 * m)
#define MARGIN (3.0 * m)

#define WORLD_SIZE_X (ARGON_SLAB_X + MARGIN)
#define WORLD_SIZE_Y (ARGON_SLAB_Y + MARGIN)
#define WORLD_SIZE_Z (ARGON_SLAB_Z + MARGIN)

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
};

#endif //CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH
