//
// Created by Jack Xu on 4/14/23.
//

#ifndef CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH
#define CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class DuneFDDetectorConstruction: public G4VUserDetectorConstruction {
    public:
        DuneFDDetectorConstruction();
        ~DuneFDDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

        G4double GetWorldSizeX() {return worldSizeX;}
        G4double GetWorldSizeY() {return worldSizeY;}
        G4double GetWorldSizeZ() {return worldSizeZ;}

    private:
        G4double worldSizeX, worldSizeY, worldSizeZ;
};

#endif //CEVNS_SIM_DUNEFDDETECTORCONSTRUCTION_HH
