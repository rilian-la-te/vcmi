#!/bin/sh

# Install nsis for installer creation
sudo apt-get install -qq nsis libarchive-dev libgpgme-dev libssl-dev ninja-build

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

pacman -Syy --noconfirm -r msys2-root --config CI/mxe-msys/pacman-mingw.conf
pacman --noconfirm -r msys2-root --config CI/mxe-msys/pacman-mingw.conf -Sy $MXE_TARGET-boost $MXE_TARGET-luajit $MXE_TARGET-ffmpeg \
$MXE_TARGET-tbb $MXE_TARGET-sdl2 $MXE_TARGET-sdl2_image $MXE_TARGET-sdl2_mixer $MXE_TARGET-sdl2_ttf \
$MXE_TARGET-minizip2 $MXE_TARGET-qt6-base
