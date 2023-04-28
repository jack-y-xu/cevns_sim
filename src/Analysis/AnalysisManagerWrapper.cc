//
// Created by Jack Xu on 4/28/23.
//

#include "AnalysisManagerWrapper.hh"
#include "G4UnitsTable.hh"

AnalysisManagerWrapper::AnalysisManagerWrapper(const std::string& outputFileName) {
    analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);

    // Create and configure the histogram
    histogramID = analysisManager->CreateH1("histogram", "Histogram of Hits", numberOfBins, xMin, xMax);

    // Set output file
    analysisManager->SetFileName(outputFileName);
    analysisManager->SetNtupleMerging(true);
}

AnalysisManagerWrapper::~AnalysisManagerWrapper() {
    delete G4AnalysisManager::Instance();
}

