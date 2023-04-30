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
//    G4Material* air = getAir();
    G4Material* stainlessSteel = getStainlessSteel();
    G4Box* worldBox = new G4Box("worldBox", WORLD_SIZE_X/2, WORLD_SIZE_Y/2, WORLD_SIZE_Z/2);

    worldLog = new G4LogicalVolume(worldBox, stainlessSteel, "worldLog");
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
    const G4Element* elementAr = new G4Element("Argon", "Ar", 18, 39.95 * g/mole);

    G4double z = 18;
    G4double a = 39.95 * g/mole;
    G4double density = 1.390 * g/cm3;
    G4State state = kStateLiquid;
    G4double temperature = 87.3 * kelvin;
    G4double pressure = 1.0 * atmosphere;
    G4double photonEnergy[] = {9.322158 * eV, 9.6*eV, 10.080057 * eV};
    G4double rindex[] = {1.41, 1.44,1.53};
    G4double absLength[] = {0.5 * m, 0.5  * m, 0.5*m};

    G4Material* lAr = new G4Material("LiquidArgon", z, a, density, state, temperature, pressure);

    G4MaterialPropertiesTable* lArMPT = new G4MaterialPropertiesTable();
    lArMPT->AddProperty("RINDEX", photonEnergy, rindex, 3);
    lArMPT->AddProperty("ABSLENGTH", photonEnergy, absLength, 3);
    lAr->SetMaterialPropertiesTable(lArMPT);

    return lAr;
}

G4Material* DuneFDDetectorConstruction::getAir() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    G4MaterialPropertiesTable* airMPT = new G4MaterialPropertiesTable();
    G4double energy[] = {1.0*eV, 20.0*eV};
    G4double rindex[] = {1.0, 1.0};

    airMPT->AddProperty("RINDEX", energy, rindex, 2);

    air->SetMaterialPropertiesTable(airMPT);

    return air;
}

G4Material* DuneFDDetectorConstruction::getStainlessSteel() {
    // Define stainless steel as a G4Material object
    G4Material* stainlessSteel = new G4Material("StainlessSteel", 8.06*g/cm3, 3);

    // Get the elements from the NIST database
    G4Element* elFe = G4NistManager::Instance()->FindOrBuildElement("Fe");
    G4Element* elCr = G4NistManager::Instance()->FindOrBuildElement("Cr");
    G4Element* elNi = G4NistManager::Instance()->FindOrBuildElement("Ni");

    // Set the percentage composition of each element in the material
    stainlessSteel->AddElement(elFe, 74.0*perCent);
    stainlessSteel->AddElement(elCr, 18.0*perCent);
    stainlessSteel->AddElement(elNi, 8.0*perCent);

    G4double photonEnergy[] = {1 * eV, 20.0 * eV};
    G4double absLength[] = {5 * nm, 5  * nm};
    const G4int nEntries = 2;

    G4MaterialPropertiesTable* steelMPT = new G4MaterialPropertiesTable();
    steelMPT->AddProperty("ABSLENGTH", photonEnergy, absLength, nEntries);

    stainlessSteel->SetMaterialPropertiesTable(steelMPT);

    return stainlessSteel;
}

G4Material* DuneFDDetectorConstruction::getSiPM() {

    G4double density = 2.32 * g/cm3; // Density of Silicon dioxide (SiO2)
    G4double photonEnergy[] = {9.322158 * eV, 9.6*eV, 10.080057 * eV};
    G4double rindex[] = {1.41, 1.44,1.53};
    G4double absLength[] = {1 * um, 1 * um, 1*um};
    // SETTING THIS TO A SHORT VALUE - FOR SURFACE DETECTION ONLY. NO EXP. VALUE EXISTS FOR OPTICAL PHOTONS.
    // SETTING THIS EQUAL TO ARGON TO AVOID DIRECTIONAL CHANGE OF PHOTON

    G4Material* SiPM = new G4Material("getSiPM", density, 2);
    G4Element* Si = new G4Element("Silicon", "Si", 14, 28.085 * g/mole);
    G4Element* O = new G4Element("Oxygen", "O", 8, 16.00 * g/mole);

    SiPM->AddElement(Si, 1);
    SiPM->AddElement(O, 2);

    G4MaterialPropertiesTable* SiPMMPT = new G4MaterialPropertiesTable;

    G4MaterialPropertiesTable* sipmPMT = new G4MaterialPropertiesTable();
    sipmPMT->AddProperty("RINDEX", photonEnergy, rindex, 3);
    sipmPMT->AddProperty("ABSLENGTH", photonEnergy, absLength, 3);

    SiPM->SetMaterialPropertiesTable(sipmPMT);
    return SiPM;
}


