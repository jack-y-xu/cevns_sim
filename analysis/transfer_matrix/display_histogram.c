{
    // Load the output.root file
    TFile *inputFile = new TFile("output.root", "READ");
    TTree *tree = (TTree *)inputFile->Get("detections");

    // Create a 2D histogram
    TH2D *hist = new TH2D("hist", "Normalized Histogram of numDetected vs numCreated;numCreated;numDetected", 40, 0.5, 40.5, 40, 0.5, 40.5);

    // Fill the histogram
    Double_t numCreated, numDetected;
    tree->SetBranchAddress("numCreated", &numCreated);
    tree->SetBranchAddress("numDetected", &numDetected);
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);
        hist->Fill(numCreated, numDetected);
    }

    // Normalize the histogram
    for (Int_t i = 1; i <= hist->GetNbinsX(); i++) {
        double normalization_factor = 10000.0;
        for (Int_t j = 1; j <= hist->GetNbinsY(); j++) {
            double content = hist->GetBinContent(i, j);
            hist->SetBinContent(i, j, content / normalization_factor);
        }
    }

    // Draw the histogram
    TCanvas *canvas = new TCanvas("canvas", "Normalized Histogram", 800, 600);
    hist->Draw("COLZ");
    canvas->SaveAs("normalized_histogram.png");

    // Cleanup
    delete canvas;
    delete hist;
    inputFile->Close();
    delete inputFile;
    }