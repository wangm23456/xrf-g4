#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "StackingAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4VProcess.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4TrackingManager.hh"
#include "G4LogicalVolume.hh"
#include "G4EventManager.hh"
#include "G4SteppingManager.hh"
#include "G4TrackingManager.hh"
#include "G4AdjointElectron.hh"
#include "fstream"
#include <stdlib.h>
#include "iostream"
#include "string"
#include "G4ios.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//G4double Number=0;
G4double Energy=0,Energy1=0,Energy2=0;
G4ThreeVector Direction,Direction1,Direction2;
G4ThreeVector Position,Position1,Position2;

using std::ofstream;
using std::string;

extern ofstream outfile1("./data/data1.csv");

//extern ofstream outfile2("./data/data2.txt");
//extern ofstream outfile11("./data/data3.txt");

SteppingAction::SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
	  G4StepPoint* prePoint = aStep->GetPreStepPoint();
	  G4StepPoint* postPoint = aStep->GetPostStepPoint();
	  G4Track* Track = aStep->GetTrack();

	if(postPoint->GetPhysicalVolume() != NULL)
    {
	    if((prePoint->GetPhysicalVolume()->GetName() == "world")
	    	&&(postPoint->GetPhysicalVolume()->GetName() == "sdd"))

	    {   G4double px=(postPoint->GetPosition().getX());
			G4double py=(postPoint->GetPosition().getY());
			G4double pz=(postPoint->GetPosition().getZ());
			G4String name = Track->GetDynamicParticle()->GetDefinition()->GetParticleName();
	    	G4double energy=((postPoint->GetKineticEnergy())/keV);
	    	G4double dx=(postPoint->GetMomentumDirection().getX());
			G4double dy=(postPoint->GetMomentumDirection().getY());
			G4double dz=(postPoint->GetMomentumDirection().getZ());
			G4String proname =(postPoint->GetProcessDefinedStep()->GetProcessName());
		    G4int ParentID = Track->GetParentID();
		    G4int ID=Track->GetTrackID();
//		    G4String process=Track->GetCreatorProcess()->GetProcessName();
		    G4int EventID=G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
//			G4String material=(postPoint->GetMaterial());
			G4double pox=(postPoint->GetPolarization().getX());
			G4double poy=(postPoint->GetPolarization().getY());
			G4double poz=(postPoint->GetPolarization().getZ());

			outfile1 << name << " "
					 << energy << " "
					 << px << " "
					 << py << " "
					 << pz << " "
					 << dx << " "
					 << dy << " "
					 << dz << " "
					 << ID << " "
					 << ParentID << " "
					 << EventID << " "
//					 << material << " "
					 << pox << " "
					<< poy << " "
					<< poz << " "
					//      << "proname"
					 << G4endl;

	     }

	}

}
