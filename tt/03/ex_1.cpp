#include <iostream>

using namespace std;

int *func () {
  int d[3]; //array wir hier angelegt, nachdem die Funktion aus dem Scope gerät, wir die var gelöscht
  for ( int i = 0; i < 3; ++ i )
    d[i] = 42;
  return d ;
}

int main () {
  int *dptr = func();
  cout << "Hi" << endl ;
  for ( int i = 0; i < 3; ++ i )
    cout << dptr[i] << endl ;
  return 0;
}
