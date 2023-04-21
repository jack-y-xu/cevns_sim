//
// Created by Jack Xu on 4/14/23.
//

#include "DuneFDDetectorConstruction.hh"

DuneFDDetectorConstruction::DuneFDDetectorConstruction() : G4VUserDetectorConstruction() {}

DuneFDDetectorConstruction::~DuneFDDetectorConstruction() {}

G4VPhysicalVolume* DuneFDDetectorConstruction::Construct() {

    // World volume
    placeWorld();
    placeArgonBox();
    placeSensitiveDetector();

    // Sensitive detector region (YZ plane)
    return worldPhys;
}

void DuneFDDetectorConstruction::placeWorld() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    G4Box* worldBox = new G4Box("worldBox", WORLD_SIZE_X/2, WORLD_SIZE_Y/2, WORLD_SIZE_Z/2);

    worldLog = new G4LogicalVolume(worldBox, air, "worldLog");
    worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLog, "worldPhys", 0, false, 0);
}

void DuneFDDetectorConstruction::placeArgonBox() {
    G4Material* lAr = getLiquidArgon();

    G4Box* lArBox = new G4Box("lArBox", ARGON_SLAB_X/2, ARGON_SLAB_Y/2, ARGON_SLAB_Z/2);

    lArLog = new G4LogicalVolume(lArBox, lAr, "lArLog");
    lArPhys = new G4PVPlacement(0, G4ThreeVector(), lArLog, "lArPhys", worldLog, false, 0);
}

void DuneFDDetectorConstruction::placeSensitiveDetector() {
    G4Material* SiPM = getSiPM();

    G4Box* sdBox = new G4Box("sdBox", SD_THICKNESS/2, ARGON_SLAB_Y/2, ARGON_SLAB_Z/2);
    sdLog = new G4LogicalVolume(sdBox, SiPM, "sdLog");
    sdPhys = new G4PVPlacement(0, G4ThreeVector(ARGON_SLAB_X/2 + SD_THICKNESS/2,0,0), sdLog, "sdPhys", worldLog, false, 0);

    // Set the sensitive detector
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    sd = new DuneFDSensitiveDetector("sd");
    sdManager->AddNewDetector(sd);
    sdLog->SetSensitiveDetector(sd);
}

G4Material* DuneFDDetectorConstruction::getLiquidArgon() {
    G4double density = 1.390*g/cm3;
    G4double temperature = 87.3*kelvin;
    G4double pressure = 1.0*atmosphere;
    G4Material* lAr = new G4Material("LiquidArgon", 18, 39.95*g/mole, density, kStateLiquid, temperature, pressure);
    return lAr;
}

G4Material* DuneFDDetectorConstruction::getSiPM() {
    G4double density = 2.32 * g/cm3; // Density of Silicon dioxide (SiO2)
    G4Material* SiPM = new G4Material("getSiPM", density, 2);

    G4Element* Si = new G4Element("Silicon", "Si", 14, 28.085 * g/mole);
    G4Element* O = new G4Element("Oxygen", "O", 8, 16.00 * g/mole);

    SiPM->AddElement(Si, 1);
    SiPM->AddElement(O, 2);

    return SiPM;
}


