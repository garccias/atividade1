#include <stdio.h>
#include "pico/stdlib.h"

// GPIO do LED RGB
#define RGB_GREEN 11
#define RGB_BLUE 12
#define RGB_RED 13

#define OUTPUT_MASK ((1 << RGB_BLUE) | (1 << RGB_GREEN) | (1 << RGB_RED))

uint16_t atraso = 3000; // Atraso de 3 segundos
int contador = 1; 


bool repeating_timer_callback(struct repeating_timer *t){

    if(contador>3){
        contador = 1;
    }

    switch(contador){
        case 1:
            gpio_put_masked(OUTPUT_MASK, 0); // Desligando os leds
            gpio_put(RGB_GREEN, 1); // primeiro led do semáforo (Vermelho)
            break;
        case 2:
            gpio_put_masked(OUTPUT_MASK, 0); // Desligando os leds
            gpio_put(RGB_BLUE, 1);  // Ativando o segundo led do semáforo (Amarelo, que no caso é azul)
            break;
        case 3:
            gpio_put_masked(OUTPUT_MASK, 0); // Desligando os leds
            gpio_put(RGB_RED, 1);  // Ativando o terceiro led do semáforo (Verde)          
            break;
    }

    contador++; 
    return true; // repetindo a interrupcao
}

int main(){
    stdio_init_all();

    // máscara da GPIO utilizada
    gpio_init_mask(OUTPUT_MASK);
    gpio_set_dir_out_masked(OUTPUT_MASK);

    struct repeating_timer timer;
    add_repeating_timer_ms(atraso, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Aguarde...\n");
        sleep_ms(1000);
    }
}
