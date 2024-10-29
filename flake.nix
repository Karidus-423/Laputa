{
  description = "zig development flake";

  # Flake inputs
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";

  };

  # Flake outputs
  outputs = { self, nixpkgs, flake-utils}:
    flake-utils.lib.eachDefaultSystem (system:
    let
        pkgs = import nixpkgs {
			system = system;
			config.allowUnfree = true;
			};
    in
    {
		formatter = pkgs.nixpkgs-fmt;
        devShells.default = pkgs.mkShell {
			name = "Raylib Gamejam";
			# Programs used during runtime
            buildInputs = with pkgs;[
			clang-tools
			zig
			emscripten
			gdb
			watchexec
			raylib
            			];
			#shellHook = '' '';
		};
    });
}

