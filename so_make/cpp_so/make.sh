g++ -fPIC -shared -o libshow.so show.cpp
g++ -o myapp  main.cpp  ./libshow.so
#g++ -o myapp main.cpp  -L./  -lshow
