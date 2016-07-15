#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Orb.hh"
#include "G4Para.hh"
#include "G4Sphere.hh"
#include "G4Trap.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPVParameterisation.hh"
#include "G4Ellipsoid.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4PhysicalConstants.hh"//物理常数,真空用
#include "G4VisAttributes.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
//using std::ofstream;
//using std::string;

G4String symbol,name;
G4double a, z, density;
G4int iz, n;
G4int ncomponents, natoms;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// Get nist material manager
  G4NistManager* nistman=G4NistManager::Instance();
  G4bool isotopes = false;

  //================================================================================================================

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{  

	//parameters-------------------------------------------------------------
	  //world
	  G4double world_size = 0.2*m;
	  G4Material* world_mat = nistman->FindOrBuildMaterial("G4_AIR");
	  G4Material* Galactic = new G4Material("Galactic", 1., 1.01*g/mole,universe_mean_density,kStateGas, 0.1*kelvin, 1.e-19*pascal);
	  //

	  //j
	  G4Material* j1_mat = nistman->FindOrBuildMaterial("G4_Ni");
	  G4ThreeVector pos_j1 = G4ThreeVector(0., 0., 0.);
	  G4double j11_pxSemiAxis=0.6*cm;
	  G4double j11_pySemiAxis=0.6*cm;
	  G4double j11_pzSemiAxis=5.*cm;
	  G4double j11_pzBottomCut=-4.*cm;
	  G4double j11_pzTopCut=4.*cm;
	  //j2
	  G4double j12_pxSemiAxis=0.5*cm;
	  G4double j12_pySemiAxis=0.5*cm;
	  G4double j12_pzSemiAxis=5.*cm;
	  G4double j12_pzBottomCut=0.*cm;
	  G4double j12_pzTopCut=0.*cm;
	  //
	  //样品
	  G4double sample_pRmin=0;
	  G4double sample_pRmax=2.*cm;
	  G4double sample_pDz=1.*cm;
	  G4double sample_pSphi=0.;
	  G4double sample_pDphi=360*degree;
	  G4ThreeVector sample_pos = G4ThreeVector(0., 0.707*cm, 0.707*cm);
	  G4Element* Cr= nistman->FindOrBuildElement("Cr",isotopes);
	  G4Element* Al= nistman->FindOrBuildElement("Al",isotopes);
	  G4Element* Ca= nistman->FindOrBuildElement("Ca",isotopes);
	  G4Element* Fe= nistman->FindOrBuildElement("Fe",isotopes);
	  G4Material* SM=new G4Material(name="max",10.*g/cm3,4);
	  	  SM->AddElement(Cr, 3);
	  	  SM->AddElement(Al, 4);
	  	  SM->AddElement(Ca, 1);
	  	  SM->AddElement(Fe, 2);

	  G4double sdd_pRmin=0;
	  G4double sdd_pRmax=0.35*cm;
	  G4double sdd_pDz=0.025*cm;
	  G4double sdd_pSphi=0.;
	  G4double sdd_pDphi=360*degree;
	    G4ThreeVector sdd_pos = G4ThreeVector(0., -2.0*cm, 0.);
	    //G4Material* sdd_mat = nistman->FindOrBuildMaterial("G4_Al");
	  //散射记录
	  G4double scatter_pRmin=3.7*cm;
	  G4double scatter_pRmax=4.*cm;

  // Option to switch on/off checking of volumes overlaps
  //
  //G4bool checkOverlaps = true;
  //     
  // World------------------------------------------------------------------------------------------------------------------
  //
  G4Box* solidworld = new G4Box("world",world_size, world_size,world_size); 
  G4LogicalVolume* logicworld = new G4LogicalVolume(solidworld,Galactic,"world");
  G4VPhysicalVolume* physiworld =new G4PVPlacement(0,G4ThreeVector(),logicworld,"world",0,false,0);

  G4Sphere* solidscatter =new G4Sphere("scatter",scatter_pRmin,scatter_pRmax,0.,360*degree,0.,360*degree);
  G4LogicalVolume* logicscatter = new G4LogicalVolume(solidscatter,Galactic,"scatter");
  new G4PVPlacement(0,G4ThreeVector(0,0,0),logicscatter,"scatter",logicworld,false,0);
  /*
 //j------------------------------------------------------------------------------------------------------------------------
 //j1
 //  G4VPhysicalVolume* physij1 =
  G4Ellipsoid* solidj11 = new G4Ellipsoid("j11",j11_pxSemiAxis,j11_pySemiAxis,j11_pzSemiAxis,j11_pzBottomCut,j11_pzTopCut);
  G4Ellipsoid* solidj12 = new G4Ellipsoid("j12",j12_pxSemiAxis,j12_pySemiAxis,j12_pzSemiAxis,j12_pzBottomCut,j12_pzTopCut);
  G4SubtractionSolid* solidj1 = new G4SubtractionSolid("j1", solidj11, solidj12);
  G4LogicalVolume* logicj1 = new G4LogicalVolume(solidj1,j1_mat,"j1");
  new G4PVPlacement(0,pos_j1,logicj1,"j1",logicworld,false,0);
  //属性
  G4VisAttributes * j1_VisAtt = new G4VisAttributes(G4Colour(0.,0.,1.));
  logicj1->SetVisAttributes(j1_VisAtt);
  */
  //样品---------------------------------------------------------------------------------------------------------------------
  //
  //G4VPhysicalVolume* physisample =


  G4Tubs* solidsample = new G4Tubs("sample",sample_pRmin, sample_pRmax,sample_pDz,sample_pSphi,sample_pDphi); 
  G4LogicalVolume* logicsample = new G4LogicalVolume(solidsample,SM,"sample");
  G4RotationMatrix* sample_rotm  = new  G4RotationMatrix();
                    sample_rotm->rotateX(45*degree);
  new G4PVPlacement(sample_rotm,sample_pos,logicsample,"sample",logicworld,false,0);

  G4Tubs* solidsdd = new G4Tubs("sdd",sdd_pRmin, sdd_pRmax,sdd_pDz,sdd_pSphi,sdd_pDphi);
    G4LogicalVolume* logicsdd = new G4LogicalVolume(solidsdd,Galactic,"sdd");
    G4RotationMatrix* sdd_rotm  = new  G4RotationMatrix();
                      sdd_rotm->rotateX(90*degree);
    new G4PVPlacement(sdd_rotm,sdd_pos,logicsdd,"sdd",logicworld,false,0);


return physiworld;
}
