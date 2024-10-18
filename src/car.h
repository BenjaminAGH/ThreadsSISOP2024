#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <mutex>

class car{
    private:
        int id;
        int velocidad;
        int distancia_total;
        static std::mutex mutex; 
    public:
        car(int id);
        int avanzar(int tiempo);
        int get_distancia_total();
        int get_id();
};

#endif