% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/vina.R
\name{vina}
\alias{vina}
\title{Run Autodock Vina}
\usage{
vina(ligand_name, rigid_name = NULL, flex_name = NULL,
  out_name = NULL)
}
\arguments{
\item{ligand_name}{filepath for PDBQT file containing ligand}

\item{rigid_name}{filepath for PDBQT file containing target}

\item{flex_name}{filepath for PDBQT file containing flex}

\item{out_name}{filepath where the output mode will be written}
}
\value{
No return as the results as written to file
}
\description{
Run Autodock Vina
}
\examples{
ligand_path = system.file("extdata", "ligand.pdbqt", package="autodockr")
rigid_path = system.file("extdata", "target.pdbqt", package="autodockr")
vina(ligand_name=ligand_path, rigid_name=rigid_path)

}
