{ pkgs ? import <nixpkgs> {} }:

let
  avrToolchain = pkgs.pkgsCross.avr.buildPackages;
in
pkgs.mkShell {
  nativeBuildInputs = [
    pkgs.cmake
    pkgs.gnumake
    pkgs.avrdude
    avrToolchain.gcc 
    pkgs.pkgsCross.avr.libcCross
  ];

  shellHook = ''
    export CC="${avrToolchain.gcc}/bin/avr-gcc"
    export CXX="${avrToolchain.gcc}/bin/avr-g++"
    
    echo "Environment ready for ATmega328P!"
  '';
}