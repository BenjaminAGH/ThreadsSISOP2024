/**
Se solicita simular una carrera de autos utilizando programacion multihebras. Cada automovil 
competidor correra en una hebra distinta. La carrera consiste en que cada auto recorrera una 
distancia de M metros en intervalos de tiempo aleatorios.

CADA AUTOMOVIL:
- Tendra un identificador unico (ej: Auto1, Auto2, etc.). 
- Avanzara una cantidad aleatoria de metros en cada iteracion. 
- Se  detendra  por un tiempo  aleatorio (representando la velocidad 
  aleatoria del auto) en cada iteracion.
- La carrera finalizara cuando todos los autos hayan terminado el recorrido

REQUISITOS:
Utilizar la biblioteca thread de C++ para manejar las hebras (cada auto en una hebra
separada). Por cada auto y en cada iteracion, calcular un valor  aleatorio  para  la
distancia que avanza (m´aximo de 10 metros) y cambia la velocidad (entre 100-500 ms).
Mostrar el avance de cada auto en tiempo real en la terminal. La carrera debe tener}
un ganador y mostrar el orden de llegada. La distancia total en  metros  (M)  de  la 
carrera y el numero de autos (N) se deben indicar  como  parametros  al  iniciar  la 
carrera.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cstdlib>
#include <ctime>

#include "car.h"

using namespace std;

const int Meta = 500;

void carrera(car &auto_ref){
    while(auto_ref.get_distancia_total() < Meta) {
        int distancia = auto_ref.avanzar(1);
        if(distancia == 0) {
            cout << "AUTO " << auto_ref.get_id() << " se DETUVO" << endl;
        } else {
            cout << "Auto " << auto_ref.get_id() << " avanzo " << distancia << " metros" << endl;
            cout << "Distancia total: " << auto_ref.get_distancia_total() << endl;
        }
    }
    cout << "Auto " << auto_ref.get_id() << " ha llegado a la meta" << endl;
}

int main(){
    srand(time(0));
    const int N = 5;

    vector<car> autos;
    for(int i = 1; i <= N; ++i) {
        autos.emplace_back(i);
    }

    vector<thread> threads;
    for(int i = 0; i < N; ++i) {
        threads.push_back(thread(carrera, ref(autos[i])));
    }

    for(auto& t : threads) {
        t.join();
    }

    cout << "La carrera ha terminado!" << endl;
    return 0;

  return 0;
}