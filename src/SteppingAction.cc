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
//ofstream outfile1("id.txt");
ofstream outfile1("./data/Position.txt");
ofstream outfile2("./data/Energy.txt");
ofstream outfile3("./data/Direction.txt");
ofstream outfile4("./data/ID.txt");
ofstream outfile5("./data/part.txt");

ofstream outfile6("./data/Position1.txt");
ofstream outfile7("./data/Energy1.txt");
ofstream outfile8("./data/Direction1.txt");
ofstream outfile9("./data/ID1.txt");
ofstream outfile10("./data/part1.txt");

ofstream outfile11("./data/Position2.txt");
ofstream outfile12("./data/Energy2.txt");
ofstream outfile13("./data/Direction2.txt");
ofstream outfile14("./data/ID2.txt");
ofstream outfile15("./data/part2.txt");

//extern G4int eventid;

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
//(Track->GetDynamicParticle()->GetDefinition()->GetParticleName()==("gamma"))&&
	if(postPoint->GetPhysicalVolume() != NULL)
 {

	    if((prePoint->GetPhysicalVolume()->GetName() == "sample")
	    	&&(postPoint->GetPhysicalVolume()->GetName() == "world"))
	  {     Position=(postPoint->GetPosition());
  	        outfile1 << Position << G4endl;
	    	Energy=((postPoint->GetKineticEnergy())/keV);
	    	outfile2 << Energy<< G4endl;
	    	Direction=(postPoint->GetMomentumDirection());
		    outfile3 << Direction << G4endl;
		    G4String name =(postPoint->GetProcessDefinedStep()->GetProcessName());
		    outfile4 << name << G4endl;
		    G4int ParentID = Track->GetParentID();
		    G4int ID=Track->GetTrackID();
//		    G4String process=Track->GetCreatorProcess()->GetProcessName();
		    G4String part = Track->GetDynamicParticle()->GetDefinition()->GetParticleName();
		    G4int eventid=G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
		    outfile5 <<eventid<<" "<<part<<" "<<ID<<" "<< ParentID << G4endl;
	  }

	    if((prePoint->GetPhysicalVolume()->GetName() == "world")
	    	    	&&(postPoint->GetPhysicalVolume()->GetName() == "sdd"))
	    	  {     Position1=(postPoint->GetPosition());
	      	        outfile6 << Position1 << G4endl;
	    	    	Energy1=((postPoint->GetKineticEnergy())/keV);
	    	    	outfile7 << Energy1<< G4endl;
	    	    	Direction1=(postPoint->GetMomentumDirection());
	    		    outfile8 << Direction1 << G4endl;
	    		    G4String name1 =(prePoint->GetProcessDefinedStep()->GetProcessName());
	    		    		    outfile9 << name1 << G4endl;
	    		    		    G4int ParentID1 = Track->GetParentID();
	    		    		    G4int ID1=Track->GetTrackID();
	//    		    		    G4String process1=Track->GetCreatorProcess()->GetProcessName();
	    		    		    G4String part1 = Track->GetDynamicParticle()->GetDefinition()->GetParticleName();
	    		    		    G4int eventid1=G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
	    		    		    outfile10 <<eventid1<<" "<<part1<<" "<<ID1<<" "<< ParentID1 << G4endl;
	    	  }

	    if((prePoint->GetPhysicalVolume()->GetName() == "scatter")
	    	    	  &&(postPoint->GetPhysicalVolume()->GetName() == "world"))
	    	  {     Position2=(postPoint->GetPosition());
	    	      	outfile11 << Position2 << G4endl;
	    	    	Energy2=((postPoint->GetKineticEnergy())/keV);
	    	    	outfile12 << Energy2<< G4endl;
	    	    	Direction2=(postPoint->GetMomentumDirection());
	    	    	outfile13 << Direction2 << G4endl;
	    	    	G4String name2 =(prePoint->GetProcessDefinedStep()->GetProcessName());
	    	    			    outfile14 << name2 << G4endl;
	    	    			    G4int ParentID2 = Track->GetParentID();
	    	    			    G4int ID2=Track->GetTrackID();
	 //   	    			    G4String process2=Track->GetCreatorProcess()->GetProcessName();
	    	    			    G4String part2 = Track->GetDynamicParticle()->GetDefinition()->GetParticleName();
	    	    			    G4int eventid2=G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
	    	    			    outfile15 <<eventid2<<" "<<part2<<" "<<ID2<<" "<< ParentID2 << G4endl;
	    }

     }

}
