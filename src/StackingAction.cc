
#include "StackingAction.hh"

#include "G4Track.hh"
#include "G4NeutrinoE.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction::StackingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction::~StackingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ClassificationOfNewTrack
StackingAction::ClassifyNewTrack(const G4Track* Track)
{

	//if (track->GetParentID() == 11) return fUrgent;
//	if(track->GetDefinition()->GetPDGEncoding()==11) return fKill;
//	else return fUrgent;
//  if((track->GetDefinition()->GetPDGEncoding()==11)
//				&&(track->GetPostStepPoint()->GetPhysicalVolume() != NULL))
//		{
//			if((track->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "ke")
//				|| (track->GetPostStepPoint ()->GetPhysicalVolume()->GetName()=="ba"))
//			 return fKill;
//		}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
