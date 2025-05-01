set -e
touch mydata.csv
echo "movies" > mydata.csv
echo "series" >> mydata.csv
mkdir build 
cd build
cmake -G Ninja ..
ninja 
clear
echo "Set up done, run de ./run script to execute code" 