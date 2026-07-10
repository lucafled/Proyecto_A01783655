classDiagram
    class Unidad {
        -int vida
        -int salud
        -int ataque
        -int nivel
        +Unidad()
        +Unidad(int v, int a, int n)
        +getVida() int
        +getSalud() int
        +getAtaque() int
        +getNivel() int
        +setAtaque(int a) void
        +setSalud(int s) void
        +setVida(int v) void
        +setNivel(int n) void
        +porcentajeSalud() int
        +imprimeBarra() void
        +calculaAtaque(Unidad objetivo) int
        +recibeAtaque(int ptosAtaque) void
        +atacar(Unidad objetivo) void
        +imprimir() void
    }

    class Guerrero {
        -int fuerza
        +Guerrero()
        +Guerrero(int v, int a, int n, int f)
        +calculaAtaque(Unidad objetivo) int
        +recibeAtaque(int ptosAtaque) void
        +imprimir() void
    }

    class Arquero {
        -int precision
        +Arquero()
        +Arquero(int v, int a, int n, int p)
        +calculaAtaque(Unidad objetivo) int
        +imprimir() void
    }

    class Mago {
        -int mana
        +Mago()
        +Mago(int v, int a, int n, int m)
        +calculaAtaque(Unidad objetivo) int
        +imprimir() void
    }

    Unidad <|-- Guerrero
    Unidad <|-- Arquero
    Unidad <|-- Mago