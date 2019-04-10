# HSCP Recasting #

## Authors: ##
[Andre Lessa](mailto:andre.lessa@ufabc.edu.br)

This repository holds the main code for recasting the 8 TeV CMS heavy stable charged particle
searcg ([CMS-EXO-12-026](https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEXO12026))
based on the fast simulation method of [CMS-EXO-13-006](https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsEXO13006).

## Pre-Requisites ##

The following pre-requisites must be installed before compiling the main code:

  * [ROOT](https://root.cern.ch/)
  * [Pythia8](http://home.thep.lu.se/~torbjorn/pythia8/) (with ROOT bindings)

## Installation/Compiling ##

In order to compile the recasting code, run:

```
make main_hscp.exe pythia8path=<PATH-TO-PYTHIA8FOLDER>
```

where PATH-TO-PYTHIA8FOLDER should point to the Pythia8 folder containing the Pythia lib and include folders.

## Running ##

Instructions for running the main code can be obtained running:

```
./main_hscp.exe -h
```

The basic required input is a (parton level) LHE or SLHA file.
For instance, running:

```
./main_hscp.exe -f example.slha -n 100 -o example.lhe
```

should generate 100 events and display the efficiencies for the given input file.
A simplified LHE output file (example.lhe) is also generated with the isolated HSCPs, their momentum,
the efficiency for each particle and the final efficiency.
This information can then be used later to rescale the efficiencies according to the HSCP lifetime.
