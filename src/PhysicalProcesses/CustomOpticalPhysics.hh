//
// Created by Jack Xu on 4/26/23.
//

#ifndef CEVNS_SIM_CUSTOMOPTICALPHYSICS_HH
#define CEVNS_SIM_CUSTOMOPTICALPHYSICS_HH 1

#include "G4OpticalPhysics.hh"
#include "G4OpticalPhoton.hh"
#include "G4ProcessVector.hh"
#include "G4ProcessManager.hh"



class CustomOpticalPhysics : public G4OpticalPhysics {
public:
    CustomOpticalPhysics();
    virtual ~CustomOpticalPhysics();

    virtual void ConstructProcess();

    void LogActiveProcesses();
    void SetVerboseLevel(G4int level);

};


#endif //CEVNS_SIM_CUSTOMOPTICALPHYSICS_HH
