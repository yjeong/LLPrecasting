# Displaced Vertex Recasting #

## Authors: ##
[Andre Lessa](mailto:andre.lessa@ufabc.edu.br)

This repository holds the main code for recasting the 13 TeV ATLAS search for displaced vertices
plus missing energy ([ATLAS-SUSY-2016-08](https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/SUSY-2016-08/))
using the efficiency grids  for event and vertex reconstruction selection provided [here](https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/SUSY-2016-08/hepdata_info.pdf).

## Pre-Requisites ##

The following pre-requisites must be installed before compiling the main code:

  * [C++ boost library](https://www.boost.org/)
  * [FastJet](http://fastjet.fr/)
  * [Pythia8](http://home.thep.lu.se/~torbjorn/pythia8) (compiled with FastJet)

## Installation/Compiling ##

In order to compile the recasting code, run:

```
make main_atlas_susy_2016_08.exe pythia8path=<PATH-TO-PYTHIA8FOLDER>
```

where <PATH-TO-PYTHIA8FOLDER> should point to the Pythia8 folder containing the Pythia lib and include folders.

## Running ##

Instructions for running the main code can be obtained running:

```
./main_atlas_susy_2016_08.exe -h
```

The basic required input is a (parton level) LHE or SLHA file.
For instance, running:

```
./main_atlas_susy_2016_08.exe -f example.slha -n 100 -o example.lhe
```

should generate 100 events and display the efficiencies for the given input file.

