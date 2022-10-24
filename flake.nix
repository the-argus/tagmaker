{
  description = "Packaging for tagmaker";

  outputs = {
    self,
    nixpkgs,
  }: let
    supportedSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];
    genSystems = nixpkgs.lib.genAttrs supportedSystems;
    pkgs = genSystems (system: import nixpkgs {inherit system;});
  in {
    packages = genSystems (system: rec {
      tagmaker = pkgs.${system}.callPackage ./. {};
      default = tagmaker;
    });

    devShell = genSystems (system:
      pkgs.${system}.mkShell {
        packages = with pkgs.${system}; [
          clang
          bear
          gtk4

          pkg-config

          meson
          ninja
        ];
      });
  };
}
