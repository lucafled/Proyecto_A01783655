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




Debido a fallas en mi VScode, corri mi codigo ussando "./exercise" en la terminal.