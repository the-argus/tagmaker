# tagmaker

A simple GTK4 program which provides a way to organize files under a unix
environment. Organize files by version numbers and tags, and then symlink
these files into target folders.

Originally designed for Minecraft modloaders such as PrismLauncher, to
fix redundancy issues between modded Minecraft instances.

## build instructions

If you have a working nix installation, just issue:

```bash
nix build
```

Otherwise, install the following dependencies:

```none
meson
ninja
pkg-config
gtk4
```

Then cd into the ``src`` directory and run the following commands:

```bash
meson setup builddir
cd builddir
meson compile
```
