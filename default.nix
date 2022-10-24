{
  clangStdenv,
  meson,
  ninja,
  pkg-config,
  gtk4,
  ...
}:
clangStdenv.mkDerivation {
  pname = "tagmaker";
  version = "0.0.1";
  src = ./src;

  nativeBuildInputs = [
    meson
    ninja
    pkg-config
    gtk4
  ];

  configurePhase = ''
    meson setup builddir
  '';

  buildPhase = let
    script = ''
      cd builddir
      meson compile
    '';
  in
    builtins.trace script script;

  installPhase = ''
    mkdir $out
    mkdir $out/bin
    mv tagmaker $out/bin/tagmaker
  '';
}
