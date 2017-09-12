
#prepare
rm -f libshow.so myapp

#make
g++ -fPIC -shared -o libshow.so show.cpp
g++ -rdynamic -o myapp main.cpp  -ldl


#run 
echo "please run: ./myapp"
#./myapp 
#./libshow.so: undefined symbol: add


