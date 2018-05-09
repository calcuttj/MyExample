#include "MyExamplePrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

MyExamplePrimaryGeneratorAction::MyExamplePrimaryGeneratorAction(
 const G4String & particleName, G4double energy,
 G4ThreeVector position, G4ThreeVector momentumDirection) : G4VUserPrimaryGeneratorAction(), fParticleGun(0){
  
  G4int nParticles = 1;
  fParticleGun = new G4ParticleGun(nParticles);

  //default particle kinematics 
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle
  = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(energy);
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momentumDirection);
  
}

MyExamplePrimaryGeneratorAction::~MyExamplePrimaryGeneratorAction(){
  delete fParticleGun;
}

void MyExamplePrimaryGeneratorAction::GeneratePrimaries(G4Event * thisEvent){
  fParticleGun->GeneratePrimaryVertex(thisEvent);
}
