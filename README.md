# PostWar

<p align="left">
    <a href="https://travis-ci.org/GCS-2017-1/postwar.svg?branch=master"><img src="https://travis-ci.org/GCS-2017-1/postwar.svg?branch=master" alt="Build Status"></a>
</p>

<p align="justify">Post War é um jogo baseado em turnos de estratégia, ele se passa em um mundo pós apocalíptico. O jogo foi desenvolvido na disciplina de Introdução aos Jogos Eletrônicos no segundo semestre de 2013 na Universidade de Brasília Campus Gama pelo grupo bryjstudios.

## Instalação

<p align="justify">Para a instalação, abra um terminal e execute os seguintes passos para instalar as seguintes bibliotecas lSDL lSDL_image lSDL_net lSDL_ttf e lSDL_mixer.

Instale o SDL1.2
- **SDL 1.2**: https://www.libsdl.org/download-1.2.php

Ou instale o SDL com sudo
```shell
$ sudo apt-get install libsdl1.2-dev && libsdl1.2debian
```

Instale o SDL Image
```shell
$ sudo apt-get install libsdl-image1.2 && libsdl-image1.2-dev
```

Instale o SDL Net
```shell
$ sudo apt-get install libsdl-net1.2 && libsdl-net1.2-dev
```

Instale o SDL Mixer
```shell
$ sudo apt-get install libsdl-mixer1.2 && libsdl-mixer1.2-dev
```

Instale o SDL ttf
```shell
$ sudo apt-get install libsdl-ttf2.0 && libsdl-ttf2.0-dev
```

Instale o CMake 3.8.1
```shell
$ wget http://www.cmake.org/files/v3.8/cmake-3.8.1.tar.gz
$ tar -xvzf cmake-3.8.1.tar.gz
$ cd cmake-3.8.1/
$ ./configure
$ sudo make install
$ cd ..
```

## Execução

Glone o repositório e entre na pasta do projeto
```shell
https://github.com/GCS-2017-1/postwar/
cd postwar
```

Crie uma pasta build, caso não exista
```shell
mkdir build
```

Entre na pasta build
```shell
cd build
```

Para criar um Makefile a partir do cmake digite:
```shell
cmake ..
```
Execute o Makefile
```shell
make
```
Execute o jogo
```shell
./postwar
```

#### Desenvolvido por bryjstudios

<p align="center"><a href="https://fga.unb.br" target="_blank"><img width="200"src="https://4.bp.blogspot.com/-0aa6fAFnSnA/VzICtBQgciI/AAAAAAAARn4/SxVsQPFNeE0fxkCPVgMWbhd5qIEAYCMbwCLcB/s1600/unb-gama.png"></a>
</p>
