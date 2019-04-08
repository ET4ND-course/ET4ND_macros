
void compilemyclass(TString myopt="fast"){
  TString opt;
  if(myopt.Contains("force")){
    opt = "kfg";
  }
  else {
    opt = "kg";
  }
  gSystem->CompileMacro("MyRandom.cxx", opt.Data());
  gSystem->CompileMacro("Neutron.cxx",opt.Data());
  gSystem->CompileMacro("Transport.cxx",opt.Data());
  gSystem->CompileMacro("simula.C",opt.Data());


}
