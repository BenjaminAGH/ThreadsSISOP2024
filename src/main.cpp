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

int Meta = 0;
int N = 0;

void carrera(car &auto_ref, vector<car> &posicionesAuto) {
    while(auto_ref.get_distancia_total() < Meta) {
        int distancia = auto_ref.avanzar(1);
        if(distancia == 0) {
            cout << "\033[31mAUTO " << auto_ref.get_id() << " se DETUVO\033[0m" << endl;
        } else {
            cout << "Auto " << auto_ref.get_id() << " avanzo " << distancia << " metros" << endl;
            cout << "Distancia total: " << auto_ref.get_distancia_total() << endl;
        }
    }
    cout << "\033[32mAuto " << auto_ref.get_id() << " ha llegado a la meta\033[0m" << endl;
    posicionesAuto.push_back(auto_ref);
}

void posiciones(vector<car> &posicionesAuto) {
    cout << endl;
    cout << "Lugar     Auto" << endl;
    cout << "───────────────" << endl;
    for(size_t i = 0; i < posicionesAuto.size(); ++i) {
        car auto_ref = posicionesAuto[i];
        cout << i + 1 << "        ";
        cout << "Auto" << auto_ref.get_id() << endl; 
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    if (argc < 3) {
        cout << "Uso: " << argv[0] << " <distancia_total> <numero_autos>" << endl;
        return 1;
    }

    Meta = atoi(argv[1]);
    N = atoi(argv[2]);

    vector<car> tablaPosiciones;
    vector<car> autos;

    cout << "\033[35mDistancia total de CARRERA: " << Meta << " metros\033[0m" << endl;
    cout << "\033[35m──────────────────────────────────────\033[0m" << endl;    

    for(int i = 1; i <= N; ++i) {
        autos.emplace_back(i);
    }

    vector<thread> threads;
    for(int i = 0; i < N; ++i) {
        threads.push_back(thread(carrera, ref(autos[i]), ref(tablaPosiciones)));
    }

    for(auto& t : threads) {
        t.join();
    }

    cout << "\033[33mLa carrera ha terminado!\033[0m" << endl;
    posiciones(tablaPosiciones);

    return 0;
}