#For Displaced DGS project
import os,sys
import numpy as np
import matplotlib.pyplot as plt
from numpy.random import normal
import pylab as pl
import matplotlib.font_manager as font_manager
from matplotlib.colors import LogNorm
import math
from matplotlib.ticker import ScalarFormatter 
import time
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
from pylab import *

plt.rc('text', usetex=True)
plt.rc('font', family='serif',variant='small-caps',weight='light')
rcParams['legend.loc'] = 'best'

chi2Fit_GGM  = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/GGM_run/BestFitParams_GGM_chi2.dat"
chi2Fit_GGM2 = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/GGM2_run/BestFitParams_GGM2_chi2.dat"
chi2Fit_RPV  = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/RPV_run/BestFitParams_RPV_chi2.dat"

chi2Fit_GGM_data= {0:[],1:[],2:[],3:[],4:[],5:[]}
chi2Fit_GGM2_data= {0:[],1:[],2:[],3:[],4:[],5:[]}
chi2Fit_RPV_data= {0:[],1:[],2:[],3:[],4:[],5:[]}

for line in open(chi2Fit_GGM,"r"):
   for i,C in enumerate(line.split()): chi2Fit_GGM_data[i].append(float(C))
for line in open(chi2Fit_GGM2,"r"):
   for i,C in enumerate(line.split()): chi2Fit_GGM2_data[i].append(float(C))
for line in open(chi2Fit_RPV,"r"):
   for i,C in enumerate(line.split()): chi2Fit_RPV_data[i].append(float(C))

ctau_GGM  = np.array(chi2Fit_GGM_data[0])
ctau_GGM2 = np.array(chi2Fit_GGM2_data[0])
ctau_RPV  = np.array(chi2Fit_RPV_data[0])

eff_GGM  = np.array(chi2Fit_GGM_data[1])
eff_GGM2 = np.array(chi2Fit_GGM2_data[1])
eff_RPV  = np.array(chi2Fit_RPV_data[1])

A_GGM  = np.array(chi2Fit_GGM_data[2])
A_GGM2 = np.array(chi2Fit_GGM2_data[2])
A_RPV  = np.array(chi2Fit_RPV_data[2])

B_GGM  = np.array(chi2Fit_GGM_data[3])
B_GGM2 = np.array(chi2Fit_GGM2_data[3])
B_RPV  = np.array(chi2Fit_RPV_data[3])

C_GGM  = np.array(chi2Fit_GGM_data[4])
C_GGM2 = np.array(chi2Fit_GGM2_data[4])
C_RPV  = np.array(chi2Fit_RPV_data[4])

chi2_GGM  = np.array(chi2Fit_GGM_data[5])
chi2_GGM2 = np.array(chi2Fit_GGM2_data[5])
chi2_RPV  = np.array(chi2Fit_RPV_data[5])

sumChi2GGM=[]
sumChi2GGM2=[]
sumChi2RPV=[]

#zip returns A , B and C s as tuples
abc_GGM=np.array(['{0}-{1}-{2}'.format(A,B,C) for A,B,C in zip(A_GGM,B_GGM,C_GGM)])
abc_GGM2=np.array(['{0}-{1}-{2}'.format(A,B,C) for A,B,C in zip(A_GGM2,B_GGM2,C_GGM2)])
abc_RPV=np.array(['{0}-{1}-{2}'.format(A,B,C) for A,B,C in zip(A_RPV,B_RPV,C_RPV)])

#print abc_GGM
setabc_GGM= set(abc_GGM)
setabc_GGM2=set(abc_GGM2)
setabc_RPV= set(abc_RPV)

################
#INDIVIDUAL FITS
################

################
# VERY IMPORTANT
# I eliminated ABC combination if on chi2 was very big.
# But, each ABC combination must be present for every ctau for chi2 to make sense.
# If not, the chi2 could be "small", but only because I remove a ctau value with big chi2.
# So need to test that every ABC combination is present 20 times (one per each ctau) as check.
# I see missing ABCs in all three models, so this check is a must to find a correct chi2.

#Need to do this to use count
listabc_GGM=list(abc_GGM)
listabc_GGM2=list(abc_GGM)
listabc_RPV=list(abc_RPV)

# abc is not necesearly common to the three models
# summing over all ctau values per benchmarck

abccomplete_GGM=[]
abccomplete_GGM2=[]
abccomplete_RPV=[]
abccomplete=[]

for abcggm in listabc_GGM:
  nabcggm=listabc_GGM.count(abcggm)
  if nabcggm ==20:
    abccomplete_GGM.append(abcggm)  
for abcggm in listabc_GGM2:
  nabcggm=listabc_GGM2.count(abcggm)
  if nabcggm ==20:
    abccomplete_GGM2.append(abcggm) 
for abcggm in listabc_RPV:
  nabcggm=listabc_RPV.count(abcggm)
  if nabcggm ==20:
    abccomplete_RPV.append(abcggm)

setabccomplete_GGM=set(abccomplete_GGM)
setabccomplete_GGM2=set(abccomplete_GGM2)
setabccomplete_RPV=set(abccomplete_RPV)

for el in setabccomplete_GGM:
    sumggm=np.sum(chi2_GGM[abc_GGM==el])
    sumChi2GGM.append(sumggm)
for el2 in setabccomplete_GGM2:
    sumggm2=np.sum(chi2_GGM2[abc_GGM2==el2])
    sumChi2GGM2.append(sumggm2)
for el3 in setabccomplete_RPV:
    sumRPV=np.sum(chi2_RPV[abc_RPV==el3])
    sumChi2RPV.append(sumRPV)

sumChi2GGM=np.array(sumChi2GGM)
sumChi2GGM2=np.array(sumChi2GGM2)
sumChi2RPV=np.array(sumChi2RPV)

# sumChi2XXX is an array of the individual sums per ABC value in the setabaccomplete lists
# print len(sumChi2GGM)
# print len(sumChi2GGM2)
# print len(sumChi2RPV)

print "------------------------------------"
print " GGM Minimum is : {0} for ABC : {1:15}".format(np.min(sumChi2GGM),abccomplete_GGM[np.argmin(sumChi2GGM)])
print " GGM2 Minimum is : {0} for ABC : {1:15}".format(np.min(sumChi2GGM2),abccomplete_GGM2[np.argmin(sumChi2GGM2)])
print " RPV Minimum is : {0} for ABC : {1:15}".format(np.min(sumChi2RPV),abccomplete_RPV[np.argmin(sumChi2RPV)])
print "------------------------------------"

##########
#In detail
# print "#########################"    
# print " GGM :"
# print len(sumChi2GGM)
# for i in range(len(sumChi2GGM)):
#     print '{0:15} {1:15} '.format(sumChi2GGM[i], abccomplete_GGM[i])
# print "#########################" 
# print "GGM2 :"   
# for i in range(len(sumChi2GGM2)):
#     print '{0:15} {1:15} '.format(sumChi2GGM2[i],abccomplete_GGM2[i])
# print "#########################"   
# print "RPV :"   
# for i in range(len(sumChi2RPV)):
#     print '{0:15} {1:15} '.format(sumChi2RPV[i],abccomplete_RPV[i])

#############################

###########
#GLOBAL FIT
###########
#########################################
#Finding a common ABC for global Chi2 fit
#########################################

finalabc=[]
for abc_el in abccomplete_GGM:
    if abc_el in abccomplete_GGM2 and abc_el in abccomplete_RPV and not abc_el in finalabc:
        finalabc.append(abc_el)

# print "finalabc : ",len(finalabc) 
# print "setfinalabc : ", len(set(finalabc))   

#This is necesary, since x==elem will give True or False if x is a set! x must be a np.array
setabccomplete_GGM=np.array(list(setabccomplete_GGM))
setabccomplete_GGM2=np.array(list(setabccomplete_GGM2))
setabccomplete_RPV=np.array(list(setabccomplete_RPV))

sumtot=[]
for elem in finalabc:
  globalChi2=sumChi2GGM[setabccomplete_GGM==elem]+sumChi2GGM2[setabccomplete_GGM2==elem]+sumChi2RPV[setabccomplete_RPV==elem]
  sumtot.append(globalChi2)
  #print elem, globalChi2

print "------------------------------------"
print " Global Chi2 Minimum is : {0} for ABC : {1:15}".format(np.min(sumtot),finalabc[np.argmin(sumtot)])
print "------------------------------------"

# ##############################################
# #Calculate chi2 back from efficiencies to test
# ##############################################
effVsLifetime_GGM_truthvertex  = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/GGM_run/effVsCtau_GGM_truthvertex_chi2_4_140_20.dat"
effVsLifetime_GGM2_truthvertex  = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/GGM2_run/effVsCtau_GGM2_truthvertex_chi2_4_140_20.dat"
effVsLifetime_RPV_truthvertex  = "/Users/ChubiCottin/HEPSoftware/pythia8209/DisplacedDGSProject/DisplacedPythiaCode/RPV_run/effVsCtau_RPV_truthvertex_chi2_4_140_20.dat"

effVsLifetime_GGM_truthvertex_data= {0:[],1:[]}
effVsLifetime_GGM2_truthvertex_data= {0:[],1:[]}
effVsLifetime_RPV_truthvertex_data= {0:[],1:[]}

for line in open(effVsLifetime_GGM_truthvertex,"r"):
   for i,C in enumerate(line.split()): effVsLifetime_GGM_truthvertex_data[i].append(float(C))
for line in open(effVsLifetime_GGM2_truthvertex,"r"):
   for i,C in enumerate(line.split()): effVsLifetime_GGM2_truthvertex_data[i].append(float(C))
for line in open(effVsLifetime_RPV_truthvertex,"r"):
   for i,C in enumerate(line.split()): effVsLifetime_RPV_truthvertex_data[i].append(float(C))

#ctau    = np.array(effVsLifetime_GGM_truthvertex_data[0])
effGGM     = np.array(effVsLifetime_GGM_truthvertex_data[1])
effGGM2     = np.array(effVsLifetime_GGM2_truthvertex_data[1])
effRPV     = np.array(effVsLifetime_RPV_truthvertex_data[1])

nominalGGMY=np.array([0.000384428,0.00337376,0.0147529,0.0386017,0.071398,0.106704,0.140067,0.167443,0.185385,0.192887,0.190499, 0.178937,0.15931,0.133699,0.105173,0.0772114,0.0528409,0.0338494,0.0204674,0.0117909]) 
errUpGGM =np.array([0.000624983, 0.00500215, 0.0206813, 0.0521283, 0.0939334, 0.138166, 0.180561, 0.216596, 0.24089, 0.251396,  0.248825,0.234204, 0.208935, 0.175658, 0.138367, 0.102017, 0.0706353, 0.0469472, 0.0308608, 0.0204484])
errDownGGM=np.array([0.000143872,0.00174537,0.00882454,0.0250751,0.0488626,0.075243,0.0995729, 0.118291,0.12988,0.134379,0.132173,0.12367,0.109685,0.0917403,0.0719785,0.0527525,0.0360273,0.0229349,0.0136653,0.00768328])

nominalGGM2Y=np.array([0.00027905, 0.00158573,0.00444047,0.00837391,0.0138648, 0.0223146, 0.0337031, 0.0460647, 0.0568487, 0.0639989, 0.0662822, 0.0638444, 0.0580141, 0.0503075, 0.0418354, 0.0333067, 0.0253138, 0.018363,  0.0126699, 0.00825567])
errUpGGM2=np.array([0.00057638,0.00325747,0.00890491,0.0155874,0.0226468,0.0327787,0.0477734,0.0652375,0.0809187,0.091208,0.0942126,0.0903937,0.0818278,0.0707009,0.0585797,0.0465041,0.0353082,0.0256887,0.0180194, 0.0123358])
errDownGGM2=np.array([0,0,0,0.00116043,0.00508285,0.0118505,0.0196329,0.026892,0.0327787,0.0367897,0.0383517,0.0372952,0.0342003,0.0299141,0.0250912,0.02011,0.0153243,0.0110833,0.0075378,0.00476993])

nominalRPVY= np.array([0.00408635, 0.020695,0.0616625,0.129378,0.214515,0.302024,0.378343,0.435519,0.471063,0.487041,0.487238,
    0.473776,0.447386,0.409167,0.361299, 0.30715,0.250353,0.193498,0.139644,0.0932954])
errUpRPV = np.array([0.00549255,0.0262213,0.0738698,0.147597,0.238275,0.331988,0.414163,0.475199,0.512501,0.528913, 0.528625, 0.51361,0.484453, 0.442379, 0.389873, 0.330769, 0.26955, 0.210944, 0.161097,0.12243])
errDownRPV =np.array([0.0026801,0.0151687,0.0494551,0.111159, 0.190755,0.272059, 0.342523,0.39584,0.429626,0.44585,0.445168,0.433941, 0.41032,0.375956,0.332725,0.283561,0.231584,0.178976,0.128627,0.0852041])

###############
#VERY IMPORTANT
###############
#Need to invert the array, since in eff table they start with big ctau!
effGGM=effGGM[::-1]
effGGM2=effGGM2[::-1]
effRPV=effRPV[::-1]

sigmaGGM = (errUpGGM-errDownGGM)/2.0
sigmaGGM2 = (errUpGGM2-errDownGGM2)/2.0
sigmaRPV = (errUpRPV-errDownRPV)/2.0

def getChi2(effM,eff0,sigmaM):
  chi2 = (effM-eff0)*(effM-eff0)/(sigmaM*sigmaM)
  return chi2

chi2FitGGM=getChi2(nominalGGMY,effGGM,sigmaGGM)
chi2FitGGM2=getChi2(nominalGGM2Y,effGGM2,sigmaGGM2)
chi2FitRPV=getChi2(nominalRPVY,effRPV,sigmaRPV)
chi2Global=chi2FitGGM+chi2FitGGM2+chi2FitRPV

print "#################################"
print "--- Testing with efficiencies ---"
print "GGM chi2Fit is : {0} ".format(np.sum(chi2FitGGM))
print "GGM2 chi2Fit sum is : {0} ".format(np.sum(chi2FitGGM2))
print "RPV chi2Fit sum is : {0} ".format(np.sum(chi2FitRPV))
print "Global chi2Fit is : {0} ".format(np.sum(chi2Global))
print "#################################"
print "Reduced GGM chi2Fit is : {0} ".format(np.sum(chi2FitGGM)/16.0)
print "Reduced GGM2 chi2Fit sum is : {0} ".format(np.sum(chi2FitGGM2)/16.0)
print "Reduced RPV chi2Fit sum is : {0} ".format(np.sum(chi2FitRPV)/16.0)
print "Reduced global chi2Fit is : {0} ".format(np.sum(chi2Global)/16.0)

