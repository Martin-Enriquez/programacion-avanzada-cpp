
#include <gtest/gtest.h>
#include "cola_impresion.h"


TEST(ColaImpresion, RedondeaMinutosHaciaArriba) {
    EXPECT_EQ(minutosDeImpresion(25), 3);
    EXPECT_EQ(minutosDeImpresion(11), 2);
    EXPECT_EQ(minutosDeImpresion(20), 2);
}


TEST(ColaImpresion, DivideTodosLosTrabajosGrandes) {
    ColaDeImpresion cola;

    cola.agregar(12);
    cola.agregar(45);
    cola.agregar(8);
    cola.agregar(30);

    cola.dividirGrandes();

    std::vector<int> esperados = {12, 20, 8, 20, 20, 10, 5};

    ASSERT_EQ(cola.cantidad(), esperados.size());

    for (int i = 0; i < cola.cantidad(); i++) {
        EXPECT_EQ(cola.paginasDe(i), esperados[i]);
    }
}

TEST(ColaImpresion, CalculaMinutosTotalesCorrectamente) {
    ColaDeImpresion cola;

    cola.agregar(12);
    cola.agregar(45);
    cola.agregar(8);
    cola.agregar(30);

    cola.dividirGrandes();

    EXPECT_EQ(cola.minutosTotales(), 11);
}
