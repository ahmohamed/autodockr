
#' R interface for Autodock Vina
#'
#' This is an R interface to allow calling Autodock Vina from whithin R. The package compile Vina
#' and its dependencies upon installation.
#'
#' @rawNamespace useDynLib(libvinaboost_system); useDynLib(libvinaboost_serialization); useDynLib(libvinaboost_thread); useDynLib(libvinaboost_filesystem); useDynLib(libvinaboost_program_options); useDynLib(libvinaboost_date_time); useDynLib(autodockr)
#' @author Ahmed Mohamed \email{mohamed@@kuicr.kyoto-u.ac.jp}
#' @name autodockr-package
#' @aliases autodockr
#' @docType package
#'
NULL


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
