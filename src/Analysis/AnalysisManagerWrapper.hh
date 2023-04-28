//
// Created by Jack Xu on 4/28/23.
//

#ifndef CEVNS_SIM_HISTOMANAGER_HH
#define CEVNS_SIM_HISTOMANAGER_HH 1

#include "globals.hh"
#include "G4AnalysisManager.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"

class AnalysisManagerWrapper {
public:
    AnalysisManagerWrapper(const std::string& outputFileName);
    ~AnalysisManagerWrapper();

    void recordHit(G4Step* step, G4TouchableHistory* history);

    void initializeColumns();

private:
    G4AnalysisManager* analysisManager;
    G4String fileName;
    int histogramID;
};


#endif //CEVNS_SIM_HISTOMANAGER_HH
