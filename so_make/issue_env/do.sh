
#prepare
rm -f libshow.so libshow2.so myapp

#make
g++ -fPIC -shared -o libshow.so show.cpp
g++ -fPIC -shared -o libshow2.so show2.cpp
g++ -rdynamic -o myapp main.cpp  -ldl  -lshow2 -L./
#g++ -o myapp main.cpp  -ldl


#run 
echo "please run: ./myapp"
#./myapp 
#./libshow.so: undefined symbol: add


