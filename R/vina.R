
#' R interface for Autodock Vina
#'
#' This is an R interface to allow calling Autodock Vina from whithin R. The package compile Vina
#' and its dependencies upon installation.
#' 
#' @author Ahmed Mohamed \email{mohamed@@kuicr.kyoto-u.ac.jp}
#' @name autodockr-package
#' @aliases autodockr
#' @docType package
#'
NULL


.onLoad<- function(lib, pkg){
	libs = paste(
		"libvinaboost",
		c("system", "filesystem", "thread", "program_options", "date_time", "serialization"),
		collapse="|",
		sep="_")
	pattern=paste0("(", libs, ")\\.(so|dylib|dll)")

	libs = list.files(
		path=system.file("boostlibs", package="autodockr"),
		pattern=pattern,
		ignore.case=TRUE,
		full.names=TRUE
	)

	# boost_system lib has to be loaded first. Other libs link to it.
	libs = c(libs[grep("_system\\.", libs)], libs[-grep("_system\\.", libs)])

	lapply(libs, dyn.load)
	library.dynam("autodockr", package="autodockr", lib.loc=NULL)
}

#' Run Autodock Vina
#'
#' @param ligand_name filepath for PDBQT file containing ligand
#' @param rigid_name filepath for PDBQT file containing target
#' @param flex_name filepath for PDBQT file containing flex
#' @param out_name filepath where the output mode will be written
#'
#' @return No return as the results as written to file
#' @export
#'
#' @examples
#' ligand_path = system.file("extdata", "ligand.pdbqt", package="autodockr")
#' rigid_path = system.file("extdata", "target.pdbqt", package="autodockr")
#' vina(ligand_name=ligand_path, rigid_name=rigid_path)
#'
vina <- function(ligand_name, rigid_name=NULL, flex_name=NULL, out_name=NULL) {
  if(is.null(rigid_name))
    rigid_name = character(0)

  if(is.null(flex_name))
    flex_name = character(0)

  if(is.null(out_name))
    out_name = character(0)

  .C("vina",
    rigid_name, flex_name, ligand_name, out_name,
  PACKAGE="autodockr")
}
