#!/bin/bash
echo "deploy robot2"
echo "set rights"
chmod +x src/compile.sh
chmod +x ir-remote/setup.sh
chmod +x lib/load_repos.sh
chmod +x src/core/compile.sh
chmod +x src/test_units/display/compile.sh
chmod +x src/test_units/drive/compile.sh
chmod +x src/test_units/io/compile.sh
chmod +x src/test_units/net/compile.sh
chmod +x src/test_units/sonar/compile.sh
chmod +x src/ir-remote/compile.sh
echo "load libraries"
cd lib
./load_repos.sh
cd ../src
echo "compile"
./compile.sh
echo "setup ir remote"
cd ../ir-remote
./setup.sh
echo "ready"
# echo "run ir remote"
# irexec /etc/lirc/lircrc