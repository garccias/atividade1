# 🚦 Projeto de Semáforo com RP2040 - Embarcatech

## 📜 Descrição
Este projeto foi desenvolvido como parte do curso Embarcatech, com o objetivo de criar um semáforo utilizando a função `add_repeating_timer_ms()`, presente na ferramenta Pico SDK. A temporização do semáforo é de 3 segundos para cada alteração de sinal. 

## 🎯 Objetivos
- Compreender o funcionamento de temporizadores em microcontroladores.
- Implementar e configurar um semáforo usando LEDs.
- Utilizar a função de call-back do temporizador para alterar o estado dos LEDs.
- Imprimir mensagens periódicas na porta serial.
- Realizar um experimento utilizando a Ferramenta Educacional BitDogLab com um LED RGB.

## 🧩 Componentes Utilizados
- **Microcontrolador:** Raspberry Pi Pico W.
- **03 LEDs:** Vermelho, Amarelo e Verde.
- **03 Resistores de 330 Ω.**

## 💡 Funcionalidades Implementadas
1. **Sequência de LEDs do Semáforo:** 
   - O semáforo inicia com o LED vermelho aceso, depois alterna para amarelo(azul) e, em seguida, verde.
   - Cada alteração de sinal ocorre após 3 segundos (3.000ms).
2. **Temporizador:**
   - A mudança de estado dos LEDs é implementada na função de call-back do temporizador.
3. **Impressão de Mensagens na Porta Serial:**
   - A rotina principal imprime informações a cada segundo (1.000ms) na porta serial.
4. **Experimento com LED RGB:**
   - O LED RGB é utilizado para simular o semáforo com as cores vermelho, amarelo e verde, utilizando as GPIOs 11, 12 e 13.

## 🛠️ Organização do Código
O código está bem estruturado e comentado para facilitar o entendimento. Inclui o uso da função `add_repeating_timer_ms()` para controlar a temporização dos LEDs.

## 📦 Como Executar o Projeto
1. Clone este repositório:
    ```bash
    git clone https://github.com/garccias/atividade1.git
    cd atividade1
    ```
2. Compile o projeto utilizando CMake e Ninja:
    ```bash
    mkdir build
    cd build
    cmake -G "Ninja" ..
    ninja
    ```
3. Carregue o arquivo `.uf2` gerado na placa Raspberry Pi Pico W.
