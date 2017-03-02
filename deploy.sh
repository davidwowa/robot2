#!/bin/bash
echo "deploy robot2"
echo "set rights"
chmod +x src/compile.sh
chmod +x ir-remote/setup.sh
chmod +x lib/load_repos.sh
echo "load libraries"
cd lib
load_repos.sh
cd ../src
echo "compile"
compile.sh
echo "setup ir"
cd ../ir-remote
ir-remote/setup.sh
echo "ready"