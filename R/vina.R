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
