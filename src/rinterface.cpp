#include <R.h>
#include <Rmath.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include "vina/main/main.h"
#include "vina/main/vina_error.h"
#include <string>
#include <boost/optional.hpp>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
  void vina(char** rigid_name, char** flex_name, char** ligand_name, char** out_name) {
    boost::optional<std::string> rigid_name_opt, flex_name_opt, out_name_opt;

    Rprintf("ligand %s \n", ligand_name[0]);

    if (rigid_name) {
      Rprintf("rigid %s \n", rigid_name[0]);
      rigid_name_opt = std::string(rigid_name[0]);
    }
    if (flex_name) {
      Rprintf("flex %s \n", flex_name[0]);
      flex_name_opt = std::string(flex_name[0]);
    }if (out_name) {
      Rprintf("out %s \n", out_name[0]);
      out_name_opt = std::string(out_name[0]);
    }


    try{
  		vina_cpp(rigid_name_opt, flex_name_opt, std::string(ligand_name[0]), out_name_opt);
  	}
  	catch(vina_error& e) {
  		error(e.error_message.c_str());
  	}


  }
#ifdef __cplusplus
}
#endif
