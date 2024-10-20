#include "car.h"
using namespace std;

mutex car::mutex;

car::car(int id) : id(id), velocidad(0), distancia_total(0) {}

int car::avanzar(int tiempo){
    lock_guard<std::mutex> lock(mutex);
    
    int probabilidad_detencion = rand() % 100;
    if(probabilidad_detencion < 10){
        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 400));
        return 0;
    }
    
    velocidad = 1 + rand() % 10;
    int distancia = velocidad * tiempo;
    distancia_total += distancia;

    this_thread::sleep_for(chrono::milliseconds(100 + rand() % 400));
    return distancia;
}

int car::get_distancia_total(){
    return distancia_total;
}

int car::get_id(){
    return id;
}