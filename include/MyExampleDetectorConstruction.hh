#ifndef MyExampleDetectorConstruction_h
#define MyExampleDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class MyExampleDetectorConstruction : public G4VUserDetectorConstruction{

  public:
    MyExampleDetectorConstruction();
    virtual ~MyExampleDetectorConstruction();

    virtual G4VPhysicalVolume * Construct();


  protected:
};

#endif
