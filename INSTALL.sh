#!/bin/bash
FILE="/tmp/out.$$"
GREP="/bin/grep"
echo "Thank you for choosing to install this beautiful piece of software created by D3PSI called pbrrenderer!"
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 1>&2
   exit 1
else
    arch=$(uname -m)
    kernel=$(uname -r)
    declare -A osInfo;
    osInfo[/etc/redhat-release]=yum
    osInfo[/etc/arch-release]=pacman
    osInfo[/etc/gentoo-release]=emerge
    osInfo[/etc/SuSE-release]=zypp
    osInfo[/etc/debian_version]=apt
    sessiontype=$(echo ${XDG_SESSION_TYPE})
    for f in ${!osInfo[@]}; do
        if [[ -f $f ]]; then
            echo "Found package manager: ${osInfo[$f]}."
            pkgman=${osInfo[$f]}
        fi
    done
    if [[ -n "$(command -v lsb_release)" ]]; then
        distroname=$(lsb_release -s -d)
    elif [[ -f "/etc/os-release" ]]; then
        distroname=$(grep PRETTY_NAME /etc/os-release | sed 's/PRETTY_NAME=//g' | tr -d '="')
    elif [[ -f "/etc/debian_version" ]]; then
        distroname="Debian $(cat /etc/debian_version)"
    elif [[ -f "/etc/redhat-release" ]]; then
        distroname=$(cat /etc/redhat-release)
    else
        distroname="$(uname -s) $(uname -r)"
    fi
    if [[ ${sessiontype} == x11 ]]; then
        session=x11
    elif [[ ${sessiontype} == gnome-wayland ]]; then
        session=wayland
    fi
    echo "Trying to install dependencies for ${distroname} using ${pkgman} on ${session}."
    if [[ ${pkgman} == yum ]]; then
        yum install cmake make pkgconf-pkg-config gcc g++ glm-devel glfw glfw-devel assimp assimp-devel SDL2 SDL2-devel SDL2_image SDL2_image-devel
    elif [[ ${pkgman} == pacman ]]; then
        pacman -Sy cmake make pkg-config gcc g++ gdb glm glfw-${session} assimp sdl2 sdl2_image
    elif [[ ${pkgman} == apt ]]; then
        apt install make pkg-config gcc g++ gdb libglfw3 libglfw3-dev libglm-dev libassimp-dev assimp-utils libegl1-mesa-dev libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev
    else
        echo "No supported package manager found!"
        exit 1
    fi
    echo "Successfully installed dependencies for your system. Building project..."
    make
    echo "Built the project. Execute it by running './RUN.sh', 'make run' or 'make debug'. Enjoy!"
    exit 0
fi
