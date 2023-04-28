//
// Created by Jack Xu on 4/14/23.
//

#include "CombinedPhysicsList.hh"

CombinedPhysicsList::CombinedPhysicsList(): G4VModularPhysicsList() {
    defaultCutValue = 1.0 * mm;
    SetVerboseLevel(1);

    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
    RegisterPhysics(new CustomOpticalPhysics());
}

CombinedPhysicsList::~CombinedPhysicsList(){

}

//void CombinedPhysicsList::ConstructParticle() {
//    G4Geantino::GeantinoDefinition();
//}
//
//void CombinedPhysicsList::ConstructProcess() {
//    AddTransportation();
//}
//
//void CombinedPhysicsList::SetCuts() {
//    SetCutsWithDefault();
//}

