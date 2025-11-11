/*
Nombres: Remmy Arevalo y Jose Mendez
Descripcion: el algoritmo solicitará iniciar sesión y la distancia a recorrer para determinar 
el precio del boleto, en caso de necesitar cambio, se devolverá al usuario en monedas de 5, 2 y 1. 
Al finalizar de ingresar datos se mostrará un resumen con el costo del boleto, el monto pagado y el cambio entregado
Fecha: 08/07/25
*/
#include <stdio.h>

int main() {
    int pago, monto, distancia, contraseña, cambio, tarifaKM;
    int moneda5, moneda2, moneda1;
    char continuar;

    int totalBoletos = 0;
    int totalRecaudado = 0;
    int totalCambio = 0;

    tarifaKM = 5;

    do {
        printf("\nInicio de sesión");
        printf("\nIngrese la contraseña de 4 dígitos numéricos: ");
        scanf("%d", &contraseña);

        if (contraseña < 1000 || contraseña > 9999) {
            printf("Contraseña incorrecta. Intente de nuevo.\n");
        }
    } while (contraseña < 1000 || contraseña > 9999);

    do {
        printf("\nIngrese la distancia de su viaje en KM: ");
        scanf("%d", &distancia);

        if (distancia <= 0) {
            printf("La distancia debe ser mayor que 0.\n");
            continue;
        }

        monto = tarifaKM * distancia;
        printf("El monto a pagar es de %d pesos\n", monto);

        printf("Ingrese el pago: ");
        scanf("%d", &pago);

        if (pago > monto) {
            cambio = pago - monto;

            moneda5 = cambio / 5;
            cambio %= 5;

            moneda2 = cambio / 2;
            cambio %= 2;

            moneda1 = cambio;

            printf("\nCambio total: %d", pago - monto);
            printf("\nMonedas de 5 pesos : %d", moneda5);
            printf("\nMonedas de 2 pesos : %d", moneda2);
            printf("\nMonedas de 1 peso  : %d\n", moneda1);


            totalBoletos++;
            totalRecaudado += monto;
            totalCambio += (pago - monto);

        } else if (pago == monto) {
            printf("Pago justo, no hay cambio.\n");

            totalBoletos++;
            totalRecaudado += monto;

        } else {
            printf("Pago insuficiente\n");
        }

        printf("\n¿Desea realizar otra operación? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');


  
    printf("\nBoletos vendidos: %d", totalBoletos);
    printf("\nTotal recaudado: %d pesos", totalRecaudado);
    printf("\nTotal de cambio dado : %d pesos", totalCambio);
    printf("\nGracias por usar la máquina de boletos. Hasta pronto");

}
