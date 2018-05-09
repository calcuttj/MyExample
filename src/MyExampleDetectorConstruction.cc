#include "MyExampleDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

MyExampleDetectorConstruction::MyExampleDetectorConstruction() : G4VUserDetectorConstruction(){ }

MyExampleDetectorConstruction::~MyExampleDetectorConstruction() { }

G4VPhysicalVolume * MyExampleDetectorConstruction::Construct(){
  
  G4NistManager * nist = G4NistManager::Instance();

  G4double radius = 1*m, height = 1*m;
  G4Material * air = nist->FindOrBuildMaterial("G4_AIR");
  G4Material * water = nist->FindOrBuildMaterial("G4_WATER");

  G4bool checkOverlaps = true;

  //World
  //
  G4Box * solidWorld = new G4Box("World", 5*radius, 5*radius, 5*radius);
  G4LogicalVolume * logicWorld = new G4LogicalVolume(solidWorld, air, "World");
  G4VPhysicalVolume * physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, checkOverlaps);

  //Disk
  //
  G4Tubs * solidDisk = new G4Tubs("Disk", 0., radius, height, 0.*deg, 360.*deg);
  G4LogicalVolume * logicDisk = new G4LogicalVolume(solidDisk, water, "Disk");
  G4VPhysicalVolume * physDisk = new G4PVPlacement(0, G4ThreeVector(), logicDisk, "Disk", logicWorld, false, 0, checkOverlaps);

  return physWorld;

}
