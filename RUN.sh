#!/bin/bash
echo "Copying executable to runtime directory..."
cp "bin/Linux/x64/pbr" "pbr"
echo "Running pbrrenderer..."
./pbr &
disown