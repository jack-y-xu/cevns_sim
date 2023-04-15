//
// Created by Jack Xu on 4/14/23.
//

#include "PhysicsList.hh"
#include "G4ParticleTypes.hh"


PhysicsList::PhysicsList():G4VUserPhysicsList() {

}

PhysicsList::~PhysicsList(){

}

void PhysicsList::ConstructParticle() {
    G4Geantino::GeantinoDefinition();
}

void PhysicsList::ConstructProcess() {
    AddTransportation();
}

void PhysicsList::SetCuts() {
    SetCutsWithDefault();
}

