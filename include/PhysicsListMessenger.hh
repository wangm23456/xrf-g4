#ifndef PhysicsListMessenger_h
#define PhysicsListMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class PhysicsList;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithABool;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PhysicsListMessenger: public G4UImessenger
{
public:

  PhysicsListMessenger(PhysicsList* );
  virtual ~PhysicsListMessenger();

  void SetNewValue(G4UIcommand*, G4String);

private:

  PhysicsList* pPhysicsList;

  G4UIdirectory*             physDir;
  G4UIcmdWithAString*        pListCmd;
  G4UIcmdWithADoubleAndUnit* gammaCutCmd;
  G4UIcmdWithADoubleAndUnit* electCutCmd;
  G4UIcmdWithADoubleAndUnit* protoCutCmd;
  G4UIcmdWithADoubleAndUnit* allCutCmd;
  G4UIcmdWithABool*          fluoCmd;
  G4UIcmdWithABool*          pixeCmd;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


