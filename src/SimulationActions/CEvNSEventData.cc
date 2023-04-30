//
// Created by Jack Xu on 4/28/23.
//

#include "CEvNSEventData.hh"

CEvNSEventData::CEvNSEventData(): G4VUserEventInformation() {};
CEvNSEventData::~CEvNSEventData() {};
void CEvNSEventData::Print() const {G4cout << "CEvNSEventData" << G4endl;}
G4int CEvNSEventData::getNumCreatedPhotons() {return numCreatedPhotons;};
void CEvNSEventData::setNumCreatedPhotons(G4int pNumPhotons) {numCreatedPhotons = pNumPhotons;};
G4ThreeVector CEvNSEventData::getOrigin() {return origin;}
void CEvNSEventData::setOrigin(const G4ThreeVector pOrigin) {origin = pOrigin;}
G4double CEvNSEventData::getTime() {return time;}
void CEvNSEventData::setTime(G4double pTime) {time = pTime;}
void CEvNSEventData::incrementNumDetected() {numDetected++;}
G4int CEvNSEventData::getNumDetected() {return numDetected;}