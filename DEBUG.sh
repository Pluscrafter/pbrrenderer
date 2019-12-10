#!/bin/bash
echo "Copying executable to runtime directory..."
cp "bin/Linux/x64/pbr" "pbr"
echo "Debugging pbrrenderer..."
gdb -ex run pbr