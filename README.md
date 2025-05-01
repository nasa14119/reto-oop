# Reto Programación Orientada a Objetos

## Install

Para poder ejecturar el proyecto en una nueva terminal en la carpeta ejecturar...
solo se tiene que hacer una vez, es para dar permisos al ejecutable.
si no se quiere usar el script se puede ejecutar las lineas en el por separado

```bash
chmod +x ./run && chmod +x ./set_up.sh # si hay algun error intente usar sudo
./set_up.sh
```

## Build

Una vez slaga el mensaje que todo esta en orden se puede ejecutar ./run.

```bash
./run
```

O se pueden ejecutar los siguientes comandos desde la carpeta del proyecto.

```bash
cd build
ninja -t clean ## Es para tenener un build limpio siempre
cmake ..
ninja
./index
```

Utilizamos ninja y cmake para este proyecto.
si no lo tiene instalado hagalo con su manajador de paquetes de preferencia
ej.

```bash
  brew install ninja cmake
```

[Github al Repositorio](https://github.com/nasa14119/reto-oop) \
[https://github.com/nasa14119/reto-oop](https://github.com/nasa14119/reto-oop)
