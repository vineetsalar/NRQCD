{
  gROOT->ProcessLine(".include /home/sudipa/LHAPDF/include");
  gSystem->Load("libLHAPDF.so");
  // gROOT->ProcessLine(".include ./inc");
  cout << "Setting the include path to: " <<  gSystem->GetIncludePath() << endl;
}
