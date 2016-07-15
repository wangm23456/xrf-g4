#include "PhysicsListMessenger.hh"

#include "PhysicsList.hh"
#include "G4RunManager.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithABool.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsListMessenger::PhysicsListMessenger(PhysicsList* pPhys)
:pPhysicsList(pPhys)
{
  physDir = new G4UIdirectory("/phys/");
  physDir->SetGuidance("physics list commands");

  pListCmd = new G4UIcmdWithAString("/phys/addPhysics",this);
  pListCmd->SetGuidance("Add modules physics list.");
  pListCmd->SetParameterName("PList",false);
  pListCmd->AvailableForStates(G4State_PreInit);

  gammaCutCmd = new G4UIcmdWithADoubleAndUnit("/phys/setGCut",this);
  gammaCutCmd->SetGuidance("Set gamma cut.");
  gammaCutCmd->SetParameterName("Gcut",false);
  gammaCutCmd->SetUnitCategory("Length");
  gammaCutCmd->SetRange("Gcut>0.0");
  gammaCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  electCutCmd = new G4UIcmdWithADoubleAndUnit("/phys/setECut",this);
  electCutCmd->SetGuidance("Set electron and positron cuts.");
  electCutCmd->SetParameterName("Ecut",false);
  electCutCmd->SetUnitCategory("Length");
  electCutCmd->SetRange("Ecut>0.0");
  electCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  protoCutCmd = new G4UIcmdWithADoubleAndUnit("/phys/setPCut",this);
  protoCutCmd->SetGuidance("Set proton cut.");
  protoCutCmd->SetParameterName("Pcut",false);
  protoCutCmd->SetUnitCategory("Length");
  protoCutCmd->SetRange("Pcut>0.0");
  protoCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  allCutCmd = new G4UIcmdWithADoubleAndUnit("/phys/setCuts",this);
  allCutCmd->SetGuidance("Set cut for all.");
  allCutCmd->SetParameterName("cut",false);
  allCutCmd->SetUnitCategory("Length");
  allCutCmd->SetRange("cut>0.0");
  allCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fluoCmd = new G4UIcmdWithABool("/phys/fluo",this);
  fluoCmd->SetGuidance("Set fluorescence on/off.");
  fluoCmd->SetParameterName("fluo",false);
  fluoCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  pixeCmd = new G4UIcmdWithABool("/phys/pixe",this);
  pixeCmd->SetGuidance("Set PIXE on/off.");
  pixeCmd->SetParameterName("pixe",false);
  pixeCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsListMessenger::~PhysicsListMessenger()
{
  delete pListCmd;
  delete gammaCutCmd;
  delete electCutCmd;
  delete protoCutCmd;
  delete allCutCmd;
  delete physDir;
  delete fluoCmd;
  delete pixeCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsListMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if( command == pListCmd )
   { pPhysicsList->AddPhysicsList(newValue);}

  if( command == gammaCutCmd )
   { pPhysicsList->SetCutForGamma(gammaCutCmd->GetNewDoubleValue(newValue));}

  if( command == electCutCmd )
   {
     G4double cut = electCutCmd->GetNewDoubleValue(newValue);
     pPhysicsList->SetCutForElectron(cut);
     pPhysicsList->SetCutForPositron(cut);
   }

  if( command == protoCutCmd )
   { pPhysicsList->SetCutForProton(protoCutCmd->GetNewDoubleValue(newValue));}

  if( command == allCutCmd )
    {
      G4double cut = allCutCmd->GetNewDoubleValue(newValue);
      pPhysicsList->SetCutForGamma(cut);
      pPhysicsList->SetCutForElectron(cut);
      pPhysicsList->SetCutForPositron(cut);
      pPhysicsList->SetCutForProton(cut);
    }

  //Notify the run manager that the physics has been modified
  G4RunManager::GetRunManager()->PhysicsHasBeenModified();

  if( command == fluoCmd )
   { pPhysicsList->SetFluorescence(fluoCmd->GetNewBoolValue(newValue));}
//
  if( command == pixeCmd )
   { pPhysicsList->SetPIXE(fluoCmd->GetNewBoolValue(newValue));}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
