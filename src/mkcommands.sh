#!/bin/sh

meson setup builddir
cd builddir
bear --output compile_commands.json -- meson compile
mv compile_commands.json ..
