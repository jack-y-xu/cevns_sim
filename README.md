# cevns_sim
Geant4 simulation of liquid argon detector written from scratch that focuses on CEvNS glow and associated processes.

Supports adding multiple types of events and switching amongst them. 


Events
____
* CEVNS: 
  * Isotropically distributed photons originating from a vertex, assumed to be the location of the cevns event
    * Location: Randomly sampled in box
    * Photon energy distribution: Uniform 123 nm - 133 nm
    * Number of photons: WIP. Currently set at 30 (need to change based on recoil energy)
    * Directions of photons: Three vector in random direction
    * Time of event: WIP, needs to be sampled from (garching rate times CEvNS event rate)
  
* Radioactive decay:
  * WIP

* Charged events:
  * WIP

DetectorConstructions
____

* DuneFDDetectorConstruction
    * 3.6m by 12m by 56m liquid argon box, and YZ surface on positive x side is assumed to be sensitive SiPM detector. Currently assuming 100% detection efficiency. 
