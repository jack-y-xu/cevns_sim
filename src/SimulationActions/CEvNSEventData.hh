//
// Created by Jack Xu on 4/28/23.
//

#ifndef CEVNS_SIM_CEVNSEVENTDATA_HH
#define CEVNS_SIM_CEVNSEVENTDATA_HH 1

#include "G4VUserEventInformation.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4Event.hh"

class CEvNSEventData: public G4VUserEventInformation {
public:
    CEvNSEventData();
    virtual ~CEvNSEventData();
    void Print() const override;
    G4int getNumCreatedPhotons();
    void setNumCreatedPhotons(G4int numPhotons);
    G4ThreeVector getOrigin();
    void setOrigin(const G4ThreeVector origin);
    G4double getTime();
    void setTime(G4double time);
    void incrementNumDetected();
    G4int getNumDetected();

private:
    G4int numCreatedPhotons;
    G4double time;
    G4ThreeVector origin;
    G4int numDetected = 0;
};


#endif //CEVNS_SIM_CEVNSEVENTDATA_HH
