{
  gROOT->ProcessLine(".include /home/vineet/LHAPDF/include");
  gSystem->Load("libLHAPDF.so");
  // gROOT->ProcessLine(".include ./inc");
  cout << "Setting the include path to: " <<  gSystem->GetIncludePath() << endl;
}
