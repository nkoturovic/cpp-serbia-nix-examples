{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    buildInputs = with pkgs; [ 
      ncurses
      cmake
      gnumake
      spdlog
      SDL2
      SDL2_ttf
  ];
}
