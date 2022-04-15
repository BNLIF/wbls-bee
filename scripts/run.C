void run(char* ratfile, int eventNo)
{
    // gROOT->ProcessLine(".x loadClasses.C");
  MCReader(ratfile, eventNo, "opticalphoton");
  MCReader(ratfile, eventNo, "Cerenkov");
    MCReader(ratfile, eventNo, "Transportation");
    MCReader(ratfile, eventNo, "Attenuation");
    MCReader(ratfile, eventNo, "G4FastSimulationManagerProcess");
}
