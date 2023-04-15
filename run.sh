cd /Users/${USER}/Neutrinos/cevns_sim
rm -rf build
mkdir build
cd build
comp ..
make -j10
./cevns_sim
