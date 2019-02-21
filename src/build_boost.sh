#!/bin/sh


cd boost_deps
./bootstrap.sh  --prefix=boost_build/
./bjam -d1 cxxflags=-w && ./bjam -d0 cxxflags=-w install
