---

# TAREA1 SSOO 2024 - Simulador carrera de autos
---
Proyecto para el ramo de Sistemas Operativos, que busca simular una carrera utilizando threats para la ejecución individual de cada auto.
## 🌟 Funcionalidades principales

### 📋 Funcionamiento del Código

El código ejecuta una carrera de autos utilizando programacion multihebras. Cada automovil competidor correra en una hebra distinta. La carrera consiste en que cada auto recorrera una distancia de M metros en intervalos de tiempo aleatorios.

CADA AUTOMOVIL:
1. Tiene un identificador unico (ej: Auto1, Auto2, etc.). 
2. Avanza una cantidad aleatoria de metros en cada iteracion. 
3. Se  detiene  por un tiempo  aleatorio en cada iteracion, determinado por una probabilidad.
4. La carrera finaliza cuando todos los autos terminan desplegando una tabla con las posiciones en las que quedaron.


## 📝 Uso del Proyecto

1. Clona este repositorio en tu máquina local.
2. Compila el proyecto usando `make` en un entorno de C++.
3. Ejecuta el código entregando los parametros <distancia_total> <numero_autos>.

### Ejecución básica:

```bash
make
./carrera 100 3
```
---

## 📖 Referencias

- [How to Change Console Color in C++?
](https://www.geeksforgeeks.org/how-to-change-console-color-in-cpp/) - Información sobre como cambiar los colores al imprimir por consola.
- [Multithreading in C++
](https://www.geeksforgeeks.org/multithreading-in-cpp/) - Ejemplo de trabajo con hebras en C++.
