#!/bin/sh

# Install nsis for installer creation
sudo apt-get install -qq nsis libarchive-dev libgpgme-dev libssl-dev ninja-build libcurl4-openssl-dev

#clone and build pacman
git clone https://gitlab.archlinux.org/pacman/pacman.git
cd pacman
git checkout v6.0.1
sudo pip3 install meson

#Taken from archlinux's PKGBUILD
meson --prefix=/usr \
        --buildtype=plain \
        -Ddoc=disabled \
        -Ddoxygen=disabled \
        -Dscriptlet-shell=/usr/bin/bash \
        -Dldconfig=/usr/bin/ldconfig \
        build

meson compile -C build
sudo meson install -C build
cd ..
rm -rf pacman
        
#now install VCMI cross-deps
mkdir -p msys2-root/var/lib/pacman

sudo pacman-key --init
sudo pacman -Syy --noconfirm -r msys2-root --config CI/mxe-msys/pacman-mingw.conf
sudo pacman --noconfirm -r msys2-root --config CI/mxe-msys/pacman-mingw.conf -Sy $MXE_TARGET-boost $MXE_TARGET-luajit $MXE_TARGET-ffmpeg \
$MXE_TARGET-tbb $MXE_TARGET-SDL2 $MXE_TARGET-SDL2_image $MXE_TARGET-SDL2_mixer $MXE_TARGET-SDL2_ttf \
$MXE_TARGET-qt6-base
