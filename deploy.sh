#!/bin/bash
echo "deploy robot2"
echo "set rights"
chmod +x src/compile.sh
chmod +x ir-remote/setup.sh
echo "compile"
src/compile.sh
echo "setup ir"
ir-remote/setup.sh
echo "ready"