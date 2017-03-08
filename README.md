# RNA-preservation-Device

The Focus of this project will be on the collection of marine biomass from seawater and metabolically ‘freezing’ the RNA profile in situ to prevent degradation and stress-induced deviance upon bringing the sample to the surface, within a simple and cheap device attached to an ROV. Current methods of RNA sample retrieval using the Niskin bottle are creating potentially unreliable results and there is a crucial requirement for sampling strategies that capture RNA profiles accurately and reliably. We aim to introduce a custom RNA profiling system with the capability to preserve the sample in situ, eliminating the archaic practice of Niskin sampling and bringing it to the 21st century. 

Using two peristaltic pumps [from a (water pistol) mechanism] to push water through a filter system. Using a timed bursts of power from a microcontroller circuit, the system can be carefully controlled to sample a specific amount of water and then the second motor can ensure the filter can be completely filled by the RNAlater® so the sample can be “Frozen” with the correct amount of solution

The code was midified from the arduino button tutorial and motor codes from adafruit. The circuit comprises the Arduino Uno and Adafruit motor shield is a ‘Hat’ for the Arduino which enables it to run up to four DC motors or 2 stepper motors and 2 servos. This is ideal for controlling the RNA profiler and Niskin integrated system.

Pumps were mounted alongside each other and tubing joined via a T-junction attached to the (external) Millipore Swinnex 25 mm filter assembly. Initial trials with centrifugal pumps (liberated from NERF Electrostorm) revealed rapid degradation of internal components exposed to seawater and RNALater, so we favoured a peristaltic pump option (ZJchao, Amazon). One way Valves were also used to ensure one way flow. 

Following activation of pump 1, seawater is pushed though the filter at a rate of ~ 2.9 ml/s, until pump 2 is engaged for a 10 s flooding with ~ 27ml of RNAlater.
