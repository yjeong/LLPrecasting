#Plotting script for displaced dgsPheno project
#Written by Giovanna Cottin
import os,sys
import numpy as np
import math
import matplotlib.pyplot as plt


bTracks               = "bTracks.dat"
displaced_bTracks     = "displaced_bTracks.dat"

Tracks_eff            = "Tracks_eff.dat"
bTracks_eff           = "bTracks_eff.dat"
displaced_Tracks_eff  = "displaced_Tracks_eff.dat"
displaced_bTracks_eff = "displaced_bTracks_eff.dat"
bTracks_after_trkeff  = "bTracks_after_trkeff.dat"
displaced_bTracks_after_trkeff="displaced_bTracks_after_trkeff.dat"


Tracks_eff_noComp            = "Tracks_eff_noComp.dat"
bTracks_eff_noComp           = "bTracks_eff_noComp.dat"
displaced_Tracks_eff_noComp  = "displaced_Tracks_eff_noComp.dat"
displaced_bTracks_eff_noComp = "displaced_bTracks_eff_noComp.dat"


bTracks_data                        = {0:[]}
displaced_bTracks_data              = {0:[]}
Tracks_eff_data                     = {0:[],1:[],2:[],3:[]}
bTracks_eff_data                    = {0:[],1:[],2:[],3:[]}
displaced_Tracks_eff_data           = {0:[],1:[],2:[],3:[]}
displaced_bTracks_eff_data          = {0:[],1:[],2:[],3:[]}
Tracks_eff_data_noComp              = {0:[],1:[],2:[],3:[]}
bTracks_eff_data_noComp             = {0:[],1:[],2:[],3:[]}
displaced_Tracks_eff_data_noComp    = {0:[],1:[],2:[],3:[]}
displaced_bTracks_eff_data_noComp   = {0:[],1:[],2:[],3:[]}
bTracks_after_trkeff_data           = {0:[]}
displaced_bTracks_after_trkeff_data = {0:[]}

for line in open(bTracks,"r"):
  for i,C in enumerate(line.split()): bTracks_data[i].append(float(C))
for line in open(displaced_bTracks,"r"):
  for i,C in enumerate(line.split()): displaced_bTracks_data[i].append(float(C))
for line in open(Tracks_eff,"r"):
  for i,C in enumerate(line.split()): Tracks_eff_data[i].append(float(C))
for line in open(bTracks_eff,"r"):
  for i,C in enumerate(line.split()): bTracks_eff_data[i].append(float(C))
for line in open(displaced_Tracks_eff,"r"):
  for i,C in enumerate(line.split()): displaced_Tracks_eff_data[i].append(float(C))
for line in open(displaced_bTracks_eff,"r"):
  for i,C in enumerate(line.split()): displaced_bTracks_eff_data[i].append(float(C))
for line in open(bTracks_after_trkeff,"r"):
  for i,C in enumerate(line.split()): bTracks_after_trkeff_data[i].append(float(C))
for line in open(displaced_bTracks_after_trkeff,"r"):
  for i,C in enumerate(line.split()): displaced_bTracks_after_trkeff_data[i].append(float(C))
for line in open(Tracks_eff_noComp,"r"):
  for i,C in enumerate(line.split()): Tracks_eff_data_noComp[i].append(float(C))
for line in open(bTracks_eff_noComp,"r"):
  for i,C in enumerate(line.split()): bTracks_eff_data_noComp[i].append(float(C))
for line in open(displaced_Tracks_eff_noComp,"r"):
  for i,C in enumerate(line.split()): displaced_Tracks_eff_data_noComp[i].append(float(C))
for line in open(displaced_bTracks_eff_noComp,"r"):
  for i,C in enumerate(line.split()): displaced_bTracks_eff_data_noComp[i].append(float(C))


btrk=np.array(bTracks_data[0])
displaced_btrk=np.array(displaced_bTracks_data[0])
trk_eff=np.array(Tracks_eff_data[0])
btrk_eff=np.array(bTracks_eff_data[0])
displaced_btrk_eff=np.array(displaced_bTracks_eff_data[0])
displaced_trk_eff=np.array(displaced_Tracks_eff_data[0])
btrk_after_trkeff=np.array(bTracks_after_trkeff_data[0])
displaced_btrk_after_trkeff=np.array(displaced_bTracks_after_trkeff_data[0])

trk_eff_noComp=np.array(Tracks_eff_data_noComp[0])
btrk_eff_noComp=np.array(bTracks_eff_data_noComp[0])
displaced_btrk_eff_noComp=np.array(displaced_bTracks_eff_data_noComp[0])
displaced_trk_eff_noComp=np.array(displaced_Tracks_eff_data_noComp[0])


print" In ", len(btrk), " events :"
#print " average trk eff on all tracks                           = ", np.average(trk_eff)
#print " average trk eff on tracks from b                        = ", np.average(btrk_eff)
print " average trk eff on displaced tracks                     = ", np.average(displaced_trk_eff)
print " average trk eff on displaced tracks from b              = ", np.average(displaced_btrk_eff)
print " average number of tracks from b                         = ", np.average(btrk)
print " average number of displaced tracks from b               = ", np.average(displaced_btrk)
print " average number of tracks from b after trk eff           = ", np.average(btrk_after_trkeff)
print " average number of displaced tracks from b after trk eff = ", np.average(displaced_btrk_after_trkeff)
print "########################################################################################"
print " average probability of all tracks                    = ", np.average(trk_eff_noComp)
print " average probability of tracks from b                 = ", np.average(btrk_eff_noComp)
print " average probability of displaced tracks              = ", np.average(displaced_trk_eff_noComp)
print " average probability of displaced tracks from b       = ", np.average(displaced_btrk_eff_noComp)
print "########################################################################################"



