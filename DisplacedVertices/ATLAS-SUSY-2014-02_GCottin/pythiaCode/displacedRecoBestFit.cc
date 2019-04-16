#include "Pythia8/Pythia.h"
#include "Pythia8/ToyDetector.h"

#include <vector>
#include <string>
#include <time.h> 
#include <iterator>

using namespace Pythia8;

double getPredictedEff(double pT, double d0, double z, double A, double B, double C){
  double eff = 0.55*(1.0-exp(-pT/A))*exp(-d0/B)*exp(-z/C);
  return eff;
}

double getChi2(double effM, double eff0, double sigmaM){
  double chi2 = (effM-eff0)*(effM-eff0)/(sigmaM*sigmaM);  
  return chi2;
}



int main() {
  //////////////////
  //ATLAS BENCHMARKS
  //////////////////

  // double nominalGGMX[1]  = {1.43845};
  // double nominalGGM2X[1] = {1.43845};
  // double nominalRPVX[1]  = {1.43845};

  // double nominalGGMY[1]  = {0.00337376};
  // double errUpGGM[1]     = {0.00500215};
  // double errDownGGM[1]   = {0.00174537};

  // double nominalGGM2Y[1] = {0.00158573};
  // double errUpGGM2[1]    = {0.00325747};
  // double errDownGGM2[1]  = {0.0};

  // double nominalRPVY[1]  = {0.020695};
  // double errUpRPV[1]     = {0.0262213};
  // double errDownRPV[1]   = {0.0151687};

  // double nominalGGMX[1]  = {37.9269};
  // double nominalGGM2X[1] = {37.9269};
  // double nominalRPVX[1]  = {37.9269};

  // double nominalGGMY[1]  = {0.190499};
  // double errUpGGM[1]     = {0.248825};
  // double errDownGGM[1]   = {0.132173};

  // double nominalGGM2Y[1] = {0.0662822};
  // double errUpGGM2[1]    = {0.0942126};
  // double errDownGGM2[1]  = {0.0383517};

  // double nominalRPVY[1]  = {0.487238};
  // double errUpRPV[1]     = {0.528625};
  // double errDownRPV[1]   = {0.433941};
 
  //Quicker fit with just three values 
  double nominalGGMX[3]  = {1.43845,37.9269,483.293};
  double nominalGGM2X[3] = {1.43845,37.9269,483.293};
  double nominalRPVX[3]  = {1.43845,37.9269,483.293};

  double nominalGGMY[3]  = {0.00337376,0.190499,0.0338494};
  double errUpGGM[3]     = {0.00500215,0.248825,0.0469472};
  double errDownGGM[3]   = {0.00174537,0.132173,0.0229349};

  double nominalGGM2Y[3] = {0.00158573,0.0662822,0.018363};
  double errUpGGM2[3]    = {0.00325747,0.0942126,0.0256887};
  double errDownGGM2[3]  = {0.0,0.0383517,0.0110833};

  double nominalRPVY[3]  = {0.020695,0.487238,0.193498};
  double errUpRPV[3]     = {0.0262213,0.528625,0.210944};
  double errDownRPV[3]   = {0.0151687,0.433941,0.178976};
/*
  double nominalGGMX[1]  = {483.293};
  double nominalGGM2X[1] = {483.293};
  double nominalRPVX[1]  = {483.293};

  double nominalGGMY[1]  = {0.0338494};
  double errUpGGM[1]     = {0.0469472};
  double errDownGGM[1]   = {0.0229349};

  double nominalGGM2Y[1] = {0.018363};
  double errUpGGM2[1]    = {0.0256887};
  double errDownGGM2[1]  = {0.0110833};

  double nominalRPVY[1]  = {0.193498};
  double errUpRPV[1]     = {0.210944};
  double errDownRPV[1]   = {0.178976};*/
  //////////////////
  //ATLAS BENCHMARKS
  //////////////////
/*  double nominalGGMX[20] = {1,1.43845, 2.06914, 2.97635, 4.28133,6.15848, 8.85867,12.7427,18.3298, 26.3665,37.9269,54.5559,78.476,112.884, 162.378, 233.572,335.982,483.293, 695.193,1000};
  double nominalGGM2X[20] = {1,1.43845, 2.06914, 2.97635, 4.28133,6.15848, 8.85867,12.7427,18.3298, 26.3665,37.9269,54.5559,78.476,112.884, 162.378, 233.572,335.982,483.293, 695.193,1000};
  double nominalRPVX[20] = {1,1.43845, 2.06914, 2.97635, 4.28133,6.15848, 8.85867,12.7427,18.3298, 26.3665,37.9269,54.5559,78.476,112.884, 162.378, 233.572,335.982,483.293, 695.193,1000};
  
  double nominalGGMY[20] = {0.000384428,0.00337376,0.0147529,0.0386017,0.071398,0.106704,0.140067,0.167443,0.185385,0.192887,0.190499, 0.178937,0.15931,0.133699,0.105173,0.0772114,0.0528409,0.0338494,0.0204674,0.0117909};
  double errUpGGM[20] = {0.000624983, 0.00500215, 0.0206813, 0.0521283, 0.0939334, 0.138166, 0.180561, 0.216596, 0.24089, 0.251396,  0.248825,0.234204, 0.208935, 0.175658, 0.138367, 0.102017, 0.0706353, 0.0469472, 0.0308608, 0.0204484};
  double errDownGGM[20] = {0.000143872,0.00174537,0.00882454,0.0250751,0.0488626,0.075243,0.0995729, 0.118291,0.12988,0.134379,0.132173,0.12367,0.109685,0.0917403,0.0719785,0.0527525,0.0360273,0.0229349,0.0136653,0.00768328};

  double nominalGGM2Y[20] ={0.00027905, 0.00158573,0.00444047,0.00837391,0.0138648, 0.0223146, 0.0337031, 0.0460647, 0.0568487, 0.0639989, 0.0662822, 0.0638444, 0.0580141, 0.0503075, 0.0418354, 0.0333067, 0.0253138, 0.018363,  0.0126699, 0.00825567};
  double errUpGGM2[20] = {0.00057638,0.00325747,0.00890491,0.0155874,0.0226468,0.0327787,0.0477734,0.0652375,0.0809187,0.091208,0.0942126,0.0903937,0.0818278,0.0707009,0.0585797,0.0465041,0.0353082,0.0256887,0.0180194,0.0123358};
  double errDownGGM2[20] = {0,0,0,0.00116043,0.00508285,0.0118505,0.0196329,0.026892,0.0327787,0.0367897,0.0383517,0.0372952,0.0342003,0.0299141,0.0250912,0.02011,0.0153243,0.0110833,0.0075378,0.00476993};

  double nominalRPVY[20]= {0.00408635, 0.020695,0.0616625,0.129378,0.214515,0.302024,0.378343,0.435519,0.471063,0.487041,0.487238,
    0.473776,0.447386,0.409167,0.361299, 0.30715,0.250353,0.193498,0.139644,0.0932954};
  double errUpRPV[20] = {0.00549255,0.0262213,0.0738698,0.147597,0.238275,0.331988,0.414163,0.475199,0.512501,0.528913, 0.528625, 0.51361,0.484453, 0.442379, 0.389873, 0.330769, 0.26955, 0.210944, 0.161097,0.12243};
  double errDownRPV[20] ={0.0026801,0.0151687,0.0494551,0.111159, 0.190755,0.272059, 0.342523,0.39584,0.429626,0.44585,0.433941, 0.41032,0.375956,0.332725,0.283561,0.231584,0.178976,0.128627,0.0852041};
*/
  clock_t begin, end;
  double time_spent;

  begin = clock();  

  Pythia pythia;
  Event& event = pythia.event;

  pythia.readFile("/r02/theory/gcottin/pythia8212/dgsReco/displacedBM.cmnd");
//  string ctauValues[21] = {"1","1","1.43845", "2.06914", "2.97635", "4.28133","6.15848", "8.85867","12.7427","18.3298", "26.3665","37.9269","54.5559","78.476","112.884", "162.378", "233.572","335.982",  "483.293", "695.193","1000"};
 
  string ctauValues[4] = {"1.43845", "1.43845", "37.9269", "483.293"};

  // string ctauValues[2] = {"1.43845", "1.43845"};
  // string ctauValues[2] = {"37.9269", "37.9269"};
  //string ctauValues[2] = {"483.293", "483.293"};

  string pythiaCtau = "1000022:tau0 = ";

  int nEvent   = pythia.mode("Main:numberOfEvents");
  int nAbort   = pythia.mode("Main:timesAllowErrors"); 

  //Files
  ofstream effVsCtau;
  effVsCtau.open("/r02/theory/gcottin/pythia8212/dgsReco/CONDOR_NEW/ABC_CONDOR_GGM_Newd0_0.55factor.dat"); 

  // Begin lifetime loop
  int iTau = 0;
  bool isInit = false;
  for (iTau=3; iTau > 0; iTau--){

    // Initialize.
    if(!isInit) {
      pythia.init();
      isInit = true;
    }

    cout<<"ctauValues[iTau] = "<<ctauValues[iTau]<<endl;
    pythia.readString(pythiaCtau + ctauValues[iTau]);

    //Since ctau loop starts at 20
    double sigmaGGM  = (errUpGGM[iTau-1]-errDownGGM[iTau-1])/2.0;
    double sigmaGGM2 = (errUpGGM2[iTau-1]-errDownGGM2[iTau-1])/2.0;
    double sigmaRPV  = (errUpRPV[iTau-1]-errDownRPV[iTau-1])/2.0;
    
    ToyDetector detector;
    std::vector<string> BadABC;
double A=4.0;
// double B=11.0;
// double C=80.0;

    //for(double A=0.4;A<1.0;A+=0.15){
      for(double B=2.0;B<30.0;B+=5){
        for(double C=20.0;C<300.0;C+=50.0){

          int iAbort = 0;
          int nJetCuts=0;
          int nPrompt=0;
          int nDVReco=0;
          int nMaterial=0;
          int nFidutial=0;
          int nTrk=0;
          int nMass=0;

          string abc=std::to_string(A)+std::to_string(B)+std::to_string(C);
          bool abcexists = std::find(std::begin(BadABC), std::end(BadABC), abc) != std::end(BadABC);
          if (abcexists) continue;
            cout<<"A,B,C,D = "<<A<<", "<<B<<" , "<<C<<" , "<<abc<<endl;  
		    //Start event loop
            int iEvent=0;
     	    for (; iEvent < nEvent; ++iEvent) {
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
     	      bool passEvtJetCuts = false; 
     	      bool passEvtDVReco = false;
     	      bool passEvtPromptCuts = true;
     	      //First find displaced truth LLP indices
     	      std::vector<int> mChiIndices;
     	      for (int iNeut= 0; iNeut < event.size(); iNeut++){
     	        if(abs(event[iNeut].id()) == 1000022) {
     	            double trux = event[iNeut].xDec() - event[iNeut].xProd();
     	            double truy = event[iNeut].yDec() - event[iNeut].yProd();
     	            double truz = event[iNeut].zDec() - event[iNeut].zProd();
     	            double trurDV = sqrt(pow2(event[iNeut].xDec())+pow2(event[iNeut].yDec()));
     	            double truzDV = abs(event[iNeut].zDec()); 
     	           //If neutralino is displaced 
     	          if ((abs(trux) > 0.00001) || (abs(truy) > 0.00001)) {
     	            double decayLength = sqrt(pow2(trux) + pow2(truy) + pow2(truz));
     	            double p = sqrt(pow2(event[iNeut].px())+pow2(event[iNeut].py())+pow2(event[iNeut].pz()));
     	            double m = event[iNeut].m();
     	            mChiIndices.push_back(iNeut);  
     	          }
     	        }
     	      }
     	      /////////////////
     	      //Event Selection
     	      /////////////////
     	     if(passEvtPromptCuts) nPrompt++;
     	       else continue;
     	      std::vector<double> JetpT;
     	      // Cuts for jets 
     	      for (unsigned long j=0; j < detector.jets.size(); j++) {
     	        JetpT.push_back(detector.jets.at(j).pT());
     	        if(abs(detector.jets.at(j).eta())<2.8) continue; 
     	      }
     	      //Here I cut on the corresponding n jets and pT (ordered in pT)
     	      bool is4j80AccepCut = (JetpT.size() > 3) && (JetpT[3] > 90.);
     	      bool is5j55AccepCut = (JetpT.size() > 4) && (JetpT[4] > 65.);
     	      bool is6j45AccepCut = (JetpT.size() > 5) && (JetpT[5] > 55.);
     	      if(is4j80AccepCut || is5j55AccepCut || is6j45AccepCut) passEvtJetCuts=true;
     	      if(passEvtJetCuts) nJetCuts++;
     	        else continue;
     	      /////////////////////////////////
     	      //DV Selection
     	      //Starts by selecting good tracks
     	      /////////////////////////////////
     	      vector <Vec4> trackProduction;
     	      vector <Vec4> trackMomenta;
     	      std::vector<int> trackIndices;
     	      std::vector<double> trackeff;
     	      trackMomenta.clear();
     	      trackProduction.clear();
     	      trackIndices.clear();
     	      trackeff.clear();
     	      //Particle event loop
     	      for (int i= 0; i < event.size(); i++){
     	        ////////////////////////////////////////////
     	        //Look for good tracks in the particle loop
     	        if(event[i].isCharged() && event[i].isFinal()){
     	          bool passTrackQuality  = true; // true unless probe otherwise
     	          double rTrk=sqrt(pow2((event[i].vProd()).px())+ pow2((event[i].vProd()).py()));
     	          double zTrk=abs((event[i].vProd()).pz());
     	          double phixy = event[i].vProd().phi();
     	          double deltaphi = phixy - event[i].phi();
     	          if (abs(deltaphi) > 3.1415) deltaphi = 2 * 3.1415 - abs(deltaphi);
     	          double d02 = rTrk*sin(deltaphi);        
     	          if(abs(d02)<2.0 || event[i].pT()<1.0 || abs(event[i].eta())>2.5) passTrackQuality=false;
     	           double iRndNumber = ((double) rand() / (RAND_MAX));
                  //if(getPredictedEff(event[i].pT(),rTrk,zTrk,A,B,C)<iRndNumber) passTrackQuality=false;
                  if(getPredictedEff(event[i].pT(),abs(d02),zTrk,A,B,C)<iRndNumber) passTrackQuality=false;
     	          if(passTrackQuality){
     	            trackIndices.push_back(i); 
     	            trackProduction.push_back(event[i].vProd());
     	            trackMomenta.push_back(event[i].p());
     	          }
     	        }
     	      } //end particle loop
     	      /////////////////////////
     	      // Vertex reconstruction
     	      ///////////////////////// 
     	      // Search through all good tracks and iteratively clusters their origins
     	      // This assumes that tracks separated 1mm will form a vertex.
     	      std::vector<std::vector<int> > ClusterIndices;
     	      std::vector<int> indexAux;
     	      if(trackProduction.size()==0) continue;
     	      for(unsigned int p1 =0;p1<trackProduction.size()-1;p1++){
     	        bool isorig=false;
     	        //track indices
     	        std::vector<int> trackidxs;
     	        trackidxs.push_back(p1);
     	        //Need not to associate the same track to other cluster
     	        //exitst will return the index where is p2
     	        bool exists = std::find(std::begin(indexAux), std::end(indexAux), p1) != std::end(indexAux);
     	        if(!exists){
     	          for(unsigned int p2=p1+1;p2<trackProduction.size();p2++ ){
     	            double distx = pow2(trackProduction[p1].px() - trackProduction[p2].px());
     	            double disty = pow2(trackProduction[p1].py() - trackProduction[p2].py());
     	            double rdist = sqrt(distx+disty);  
     	            // Find tracks less than X mm apart to form DV. Based on vertex resolution information.
     	            // Worst resolution outside third pixel layer, so merge tracks further appart ?
     	            if(rdist<1){
     	              isorig=true;
     	              trackidxs.push_back(p2);
     	              indexAux.push_back(p2);
     	              //trackidxs.size() will be the number of tracks clustered in the vertex
     	            }
     	          }
     	        }
     	        if (isorig) {
     	          ClusterIndices.push_back(trackidxs);
     	        }
     	      }
     	      std::vector<double> xDVertex;
     	      std::vector<double> yDVertex;
     	      std::vector<double> zDVertex;
     	      //Calculate DV position from the average position of tracks in cluster
     	      for(unsigned int clus=0;clus<ClusterIndices.size();clus++){
     	        double xpos = 0.0;
     	        double ypos = 0.0;
     	        double zpos = 0.0;
     	        for(unsigned int clustrk=0;clustrk<ClusterIndices[clus].size();clustrk++) {
     	          int index = ClusterIndices[clus][clustrk];
     	          xpos += trackProduction[index].px();
     	          ypos += trackProduction[index].py();
     	          zpos += trackProduction[index].pz();
     	        }
     	        //Average position of DV
     	        double xDV = xpos/ClusterIndices[clus].size();   
     	        double yDV = ypos/ClusterIndices[clus].size();   
     	        double zDV = zpos/ClusterIndices[clus].size(); 
     	        xDVertex.push_back(xDV);
     	        yDVertex.push_back(yDV);
     	        zDVertex.push_back(zDV);
     	      }//close cluster (DV)  
     	      std::vector<int> clusDVIndices;
     	      //Merge DVs less than 1 mm apart
     	      //dv1 and dv2 are cluster indices    
     	      if(xDVertex.size()==0) continue;
     	      for(unsigned int dv1=0;dv1<xDVertex.size()-1;dv1++){
     	        for(unsigned int dv2=dv1+1;dv2<xDVertex.size();dv2++){
     	          double DVdistx=xDVertex[dv1]-xDVertex[dv2];
     	          double DVdisty=yDVertex[dv1]-yDVertex[dv2];
     	          double DVdistz=zDVertex[dv1]-zDVertex[dv2];
     	          double distDV=sqrt(pow2(DVdistx)+pow2(DVdisty)+pow2(DVdistz));
     	          if(distDV <= 1){
     	            cout<<" ----- Merging Vertices ----- "<<endl;
     	            clusDVIndices.push_back(dv2);
     	            xDVertex.erase(std::begin(xDVertex)+dv2);
     	            yDVertex.erase(std::begin(yDVertex)+dv2);
     	            zDVertex.erase(std::begin(zDVertex)+dv2);
     	            ClusterIndices.erase(std::begin(ClusterIndices)+dv2);
     	            break;
     	          }
     	        }
     	      }
     	      //Reconstructed vertex in the event
     	      passEvtDVReco = true;
     	      if(passEvtDVReco) nDVReco++;
     	        else continue;
     	      // Vertex cuts
     	      bool vtxPassFidutial=false;
     	      bool vtxPassesMaterial=false; 
     	      bool vtxPassesNtrk=false;
     	      bool vtxPassesMass=false;
     	      bool vtxTruthMatched=false;
     	      //save selected DV indices
     	      std::vector<std::vector<int> > DisplacedVertexIndices;
     	      for (unsigned int dv=0;dv<xDVertex.size();dv++){
     	        double rDisplacedVertex=sqrt(pow2(xDVertex[dv])+pow2(yDVertex[dv]));
     	        double zDisplacedVertex=abs(zDVertex[dv]);
     	        //Vertex fidutial region 
     	        //It will not have much of an effect if we already required the track production not to be in this region
     	        if(zDisplacedVertex>300.) continue;
     	        if(4.>rDisplacedVertex && rDisplacedVertex>300.) continue; 
     	          vtxPassFidutial=true;
     	        //Also, Vertex must also not be inside the pixel layers
     	        if(4.5<rDisplacedVertex && rDisplacedVertex<6.0) continue;
     	        if(8.9<rDisplacedVertex && rDisplacedVertex<9.5) continue;
     	        if(12.<rDisplacedVertex && rDisplacedVertex<13.) continue;
     	          vtxPassesMaterial=true;
     	        if(ClusterIndices[dv].size()<4) continue;
     	          vtxPassesNtrk=true;
     	        //DV invariant mass calculation
     	        Vec4 total4p;
     	        Vec4 total4pPion;
     	        double trum=0.0;
     	        double trum2=0.0;
     	        double trumPion=0.0;
     	        int strack=0;
     	        //Find neutralino mother index of the track coming from the DV  
     	        std::vector<int> daughterIndices;
     	        std::vector<int> motherIndices;
     	        int nMatchedTracks = 0;
     	        //Loop over tracks from the DV 
     	        for(unsigned trackIdx=0;trackIdx<ClusterIndices[dv].size();trackIdx++){
     	          strack++;
     	          double trackX=trackProduction[trackIdx].px();
     	          double trackY=trackProduction[trackIdx].py();
     	          double trackZ=trackProduction[trackIdx].pz();
     	          double trackpX=trackMomenta[trackIdx].px();
     	          double trackpY=trackMomenta[trackIdx].py();
     	          double trackpZ=trackMomenta[trackIdx].pz();
     	          double trackpMod=sqrt(pow2(trackpX)+pow2(trackpY)+pow2(trackpZ));
     	          double seedRq = trackX*trackpX/trackpMod+trackY*trackpY/trackpMod+trackZ*trackpZ/trackpMod;
     	          //At least 2 tracks in each DV with ssedReq
     	          if(strack<=2 && seedRq< -20.) continue;
     	          int evtRecordTrackIndex=trackIndices[ClusterIndices[dv][trackIdx]];
     	          bool hasAmother = false;
     	          int  Amother = event[evtRecordTrackIndex].mother1();
     	          while(Amother > 4){
     	            if (abs(event[Amother].id()) == 1000022 ){
     	              hasAmother = true;
     	              break;
     	            }
     	            Amother = event[Amother].mother1();
     	          }
     	          bool existsLLP = std::find(std::begin(mChiIndices), std::end(mChiIndices), Amother) != std::end(mChiIndices);
     	          if(hasAmother && existsLLP){
     	            nMatchedTracks++;
     	          }
     	          //at least two matched tracks in the vertex
     	          if(nMatchedTracks>=2) {
     	            vtxTruthMatched=true;
     	          }
     	          double TrackMass=event[evtRecordTrackIndex].mCalc();
     	          //This is scalar mass of tracks contained in the vertex
     	          trum+=TrackMass;
     	          //from four momenta
     	          double particlepx = event[evtRecordTrackIndex].px();
     	          double particlepy = event[evtRecordTrackIndex].py();
     	          double particlepz = event[evtRecordTrackIndex].pz();
     	          double particleE = event[evtRecordTrackIndex].e();
     	          double particleEPion = sqrt(pow2(0.1395700)+pow2(particlepx)+pow2(particlepy)+pow2(particlepz));
     	          double TrktrumDV2 = sqrt(abs(pow2(particleE)-(pow2(particlepx)+pow2(particlepy)+pow2(particlepz))));
     	          double TrktrumDVPion=sqrt(abs(pow2(particleEPion)-(pow2(particlepx)+pow2(particlepy)+pow2(particlepz))));
     	          trum2+=TrktrumDV2;
     	          trumPion+=TrktrumDVPion;
     	          //Invariant mass of the vertex
     	          total4p+=Vec4(particlepx,particlepy,particlepz,particleE);
     	          total4pPion+=Vec4(particlepx,particlepy,particlepz,particleEPion);
     	        }
     	        double totalmPion=total4pPion.mCalc();
     	        //Cut on mDV 
     	        if(totalmPion<10.) continue;
     	          vtxPassesMass=true;
     	        //Selected DV indices  
     	        DisplacedVertexIndices.push_back(ClusterIndices[dv]);  
     	      }// close DV loop
     	      if(vtxPassFidutial) nFidutial++;
     	        else continue;
     	      if(vtxPassesMaterial) nMaterial++;
     	        else continue;
     	      if(vtxPassesNtrk && vtxTruthMatched) nTrk++;
     	        else continue;
     	      if(vtxPassesMass) nMass++;
     	        else continue;
  /*            cout<<"nMass = "<<nMass<<endl;
              cout<<"iEvent = "<<iEvent<<endl;*/
            if(nMass>100.0) break;  
     	    } // End of event loop.
		    double chi2Fit=getChi2(nominalGGMY[iTau-1],nMass*1.0/iEvent, sigmaGGM);
		    //double chi2Fit=getChi2(nominalGGM2Y[iTau-1],nMass*1.0/iEvent, sigmaGGM2);
		    //double chi2Fit=getChi2(nominalRPVY[iTau-1],nMass*1.0/iEvent, sigmaRPV);
		    cout<<"chi2 = "<<chi2Fit<<endl;
		    if(chi2Fit>200.0){
		        BadABC.push_back(abc);
		        continue;
		    }
   		effVsCtau<<ctauValues[iTau]<<" "<<setprecision(5)<<fixed<<nMass*1.0/iEvent<<" "<<A<<" "<<B<<" "<<C<<" "<<chi2Fit<<endl;
        pythia.stat();
        }//close eff param c
      }//close eff param b
    //}//close eff param a
  }//close ctau

  effVsCtau.close(); 
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  cout<<" It took : "<<time_spent<<endl;
  return 0;
}



