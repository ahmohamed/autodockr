#include <R.h>
#include <Rmath.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include "vina/main/main.h"
#include "vina/main/vina_error.h"


#ifdef __cplusplus
extern "C" {
#endif
  void vina() {
    try{
  		main_with_args("../Target/human.pdbqt", "../Ligand/human_ligand.pdbqt", "../Out/human.pdbqt_plasmo_ligand.vinaall.pdbqt");
  	}
  	catch(vina_error& e) {
  		error(e.error_message.c_str());
  	}


  }
#ifdef __cplusplus
}
#endif
