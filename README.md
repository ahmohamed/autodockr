[![Travis-CI Build Status](https://travis-ci.org/ahmohamed/autodockr.svg?branch=develop)](https://travis-ci.org/ahmohamed/autodockr)
# Introduction
This is an R interface to allow calling Autodock Vina from whithin R. The package compile Vina and its dependencies upon installation

# Installation

## From GitHub using devtools:
In R console, type:

```r
  library(devtools)
  install_github(repo="ahmohamed/autodockr")
```

## From command line
You can download the package from github and use commandline to install the package using:

```bash
R CMD INSTALL autodockr
```

# Usage
Currently there is a single function `vina` that accepts file paths for target proteins and ligands in PDBQT format. You can test run by:

```r
library(autodockr)
example(vina)
```
