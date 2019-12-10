# pbrrenderer

[![Build Status](https://travis-ci.com/D3PSI/pbrrenderer.svg?branch=master)](https://travis-ci.com/D3PSI/pbrrenderer)
[![C/C++ CI](https://github.com/D3PSI/pbrrenderer/workflows/C/C++%20CI/badge.svg)](https://github.com/D3PSI/pbrrenderer/actions?query=workflow%3A"C/C+++CI")

This repository contains my first ever physically-based rendering application, 
written in C++-17 using the OpenGL core version 4.5.  

## Installation

### Linux

The repository comes with a versatile install script. It offers support for a wide variety of distributions including Debian, Fedora and Arch/Manjaro Linux. Clone the repository and run the installer like so:

    git clone https://github.com/D3PSI/pbrrenderer.git
    cd pbrrenderer/
    sudo ./INSTALL.sh

Then, run or debug the application with `./RUN.sh` respectively `./DEBUG.sh`. If you want to recompile and 
automatically run the software, run either `make run` or `make debug`.

### Windows

Windows is currently not supported. Support will be added in future versions.

### macOS

macOS is currently not supported. Support may be added in future versions.

## Uninstallation

Just simply delete the project folder from disk:

    rm -r pbrrenderer

Thanks for the interest in the project!
