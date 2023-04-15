//
// Created by Jack Xu on 4/14/23.
//

#include "DuneFDDetectorConstruction.hh"

#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#define ARGON_SLAB_X 3.6
#define ARGON_SLAB_Y 12.0
#define ARGON_SLAB_Z 58.0

DuneFDDetectorConstruction::DuneFDDetectorConstruction() : G4VUserDetectorConstruction() {
    worldSizeX = ARGON_SLAB_X * m + 2 * m;
    worldSizeY = ARGON_SLAB_Y * m + 2 * m;
    worldSizeZ = ARGON_SLAB_Z * m + 2 * m;
}

DuneFDDetectorConstruction::~DuneFDDetectorConstruction() {}

G4VPhysicalVolume* DuneFDDetectorConstruction::Construct() {
//    G4Material* air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");

    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* liquidArgon = nistManager->FindOrBuildMaterial("G4_lAr");

    G4Box* oneBoxOnly = new G4Box("World", ARGON_SLAB_X/2 * m, ARGON_SLAB_Y/2 * m, ARGON_SLAB_Z/2 * m);
    G4LogicalVolume* logicalWithBox = new G4LogicalVolume(oneBoxOnly, liquidArgon, "World");
    G4VPhysicalVolume* physicalWorld = new G4PVPlacement(0,
                                                         G4ThreeVector(),
                                                         logicalWithBox,
                                                         "World",
                                                         0,
                                                         false,
                                                         0);

    return physicalWorld;
}