// Displaced DGS Project
// Written by Giovanna Cottin 

#include "Pythia8/Pythia.h"
#include "ToyDetector-ATLAS.h"

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace Pythia8;

//tracking efficiency parametrization
double efficiency(double pT, double r, double z){

double eff= 0.5*(1.0-exp(-pT/4.0))*exp(-z/270.0)*std::max(-0.0022*r+0.8, 0.0);
return eff;
}

int main() {
  Pythia pythia;
  Event& event = pythia.event;
  pythia.readFile("displacedBM.cmnd");

  int nEvent   = pythia.mode("Main:numberOfEvents");
  int nAbort   = pythia.mode("Main:timesAllowErrors"); 
  //Initialize.
  pythia.init();

  ofstream bTracks;
  ofstream displaced_bTracks;
  ofstream Tracks_eff;
  ofstream bTracks_eff;
  ofstream displaced_Tracks_eff;
  ofstream displaced_bTracks_eff;
  ofstream bTracks_after_trkeff;
  ofstream displaced_bTracks_after_trkeff;

  bTracks.open("bTracks.dat"); 
  displaced_bTracks.open("displaced_bTracks.dat"); 
  Tracks_eff.open("Tracks_eff_noComp.dat"); 
  bTracks_eff.open("bTracks_eff_noComp.dat"); 
  displaced_Tracks_eff.open("displaced_Tracks_eff_noComp.dat"); 
  displaced_bTracks_eff.open("displaced_bTracks_eff_noComp.dat"); 
  bTracks_after_trkeff.open("bTracks_after_trkeff.dat");
  displaced_bTracks_after_trkeff.open("displaced_bTracks_after_trkeff.dat");

  int iAbort = 0;

  ToyDetector detector;
  //Start event loop
  for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
    // Generate events. Quit if many failure.
    if (!pythia.next()) {
      event.list();
      if (++iAbort < nAbort) continue;
        cout << " Event generation aborted prematurely, owing to error!\n";
      break;
    }
    if(!detector.getObjects(event)) {
      cout << "No objects found" << endl;
    } 
    else {
       //detector.printObjects();
    }
    std::vector<int> Tracks;
    std::vector<int> displaced_Tracks;
    Tracks.clear();
    displaced_Tracks.clear();
    //Particle event loop
    for (int i= 0; i < event.size(); i++){
      //Look for all tracks in the particle loop
      if(event[i].isCharged() && event[i].isFinal()){
        Tracks.push_back(i);
        bool passTrackQuality  = true; // true unless probe otherwise
        bool isDisplaced       = true; // true unless probe otherwise
        double rTrk     = sqrt(pow2((event[i].vProd()).px())+ pow2((event[i].vProd()).py()));
        double zTrk     = abs((event[i].vProd()).pz());
        double phixy    = event[i].vProd().phi();
        double deltaphi = phixy - event[i].phi();
        if (abs(deltaphi) > 3.1415) deltaphi = 2 * 3.1415 - abs(deltaphi);
        double d0 = rTrk*sin(deltaphi);        
        //select displaced tracks 
        if(abs(d0)<2.0 || event[i].pT()<1.0 || abs(event[i].eta())>2.5) isDisplaced=false;
        if(isDisplaced){
          displaced_Tracks.push_back(i);
        }
        //Reject the track before forming the vertex 
        //double iRndNumber = ((double) rand() / (RAND_MAX));
        //if(efficiency(event[i].pT(),rTrk,zTrk)<iRndNumber) passTrackQuality=false;
        if(passTrackQuality){
          Tracks_eff<<efficiency(event[i].pT(),rTrk,zTrk)<<" "<<event[i].pT()<<" "<<rTrk<<" "<<zTrk<<endl;
        }
        if(isDisplaced && passTrackQuality){
          displaced_Tracks_eff<<efficiency(event[i].pT(),rTrk,zTrk)<<" "<<event[i].pT()<<" "<<rTrk<<" "<<zTrk<<endl;
        }
      }
    } //end particle loop 
    // cout<<" #################### "<<endl;
    // cout<<" Event "<< iEvent <<" has "<< Tracks.size()           <<" tracks "<<endl;
    // cout<<" Event "<< iEvent <<" has "<< displaced_Tracks.size() <<" displaced tracks "<<endl;
    std::vector<int> b_Tracks;
    std::vector<int> displaced_b_Tracks;
    std::vector<int> b_Tracks_after_trkeff;
    std::vector<int> displaced_b_Tracks_after_trkeff;
    b_Tracks.clear();
    displaced_b_Tracks.clear();
    //Particle event loop 
    for (int j= 0; j < event.size(); j++){
      //Look for b mothers
      bool hasAmother = false;
      int  Amother = event[j].mother1();
      while(Amother > 4){
      if (abs(event[Amother].id()) == 5 ){
      hasAmother = true;
      break;
      }
      Amother = event[Amother].mother1();
      }
      //Look for tracks in the particle loop that came from a b
      if(hasAmother && event[j].isCharged() && event[j].isFinal()){
        b_Tracks.push_back(j);
        bool passTrackQuality  = true; // true unless probe otherwise
        bool isDisplaced       = true; // true unless probe otherwise
        double rTrk     = sqrt(pow2((event[j].vProd()).px())+ pow2((event[j].vProd()).py()));
        double zTrk     = abs((event[j].vProd()).pz());
        double phixy    = event[j].vProd().phi();
        double deltaphi = phixy - event[j].phi();
        if (abs(deltaphi) > 3.1415) deltaphi = 2 * 3.1415 - abs(deltaphi);
        double d0 = rTrk*sin(deltaphi);        
        //select displaced tracks 
        if(abs(d0)<2.0 || event[j].pT()<1.0 || abs(event[j].eta())>2.5) isDisplaced=false;
        if(isDisplaced){
          displaced_b_Tracks.push_back(j);
        }
        //Reject the track before forming the vertex 
        double iRndNumber = ((double) rand() / (RAND_MAX));
        //if(efficiency(event[j].pT(),rTrk,zTrk)<iRndNumber) passTrackQuality=false;
        if(passTrackQuality){
          b_Tracks_after_trkeff.push_back(j);
          bTracks_eff<<efficiency(event[j].pT(),rTrk,zTrk)<<" "<<event[j].pT()<<" "<<rTrk<<" "<<zTrk<<endl;
        }
        if(isDisplaced && passTrackQuality){
          displaced_b_Tracks_after_trkeff.push_back(j);
          displaced_bTracks_eff<<efficiency(event[j].pT(),rTrk,zTrk)<<" "<<event[j].pT()<<" "<<rTrk<<" "<<zTrk<<endl;
        }
      }
    } //end particle loop
    // cout<<" Event "<< iEvent <<" has "<< b_Tracks.size()           <<" b tracks "          <<endl;
    // cout<<" Event "<< iEvent <<" has "<< displaced_b_Tracks.size() <<" displaced b tracks "<<endl;
    bTracks<<b_Tracks.size()<<endl;
    displaced_bTracks<<displaced_b_Tracks.size()<<endl;
    bTracks_after_trkeff<<b_Tracks_after_trkeff.size()<<endl;
    displaced_bTracks_after_trkeff<<displaced_b_Tracks_after_trkeff.size()<<endl;
  } //End of event loop.

  pythia.stat();

  bTracks.close();
  displaced_bTracks.close();
  Tracks_eff.close();
  bTracks_eff.close();
  displaced_Tracks_eff.close();
  displaced_bTracks_eff.close();

  bTracks_after_trkeff.close();
  displaced_bTracks_after_trkeff.close();

  return 0;
}




