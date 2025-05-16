# EDGE COMPUTING CP-2
# 🔅 Sistema de Monitoramento de Luminosidade, umidade e Temperatura para Vinheria Agnello

## ♦ Descrição do Projeto
A qualidade do vinho pode ser impactada diretamente por fatores como temperatura, umidade e luminosidade. O sistema desenvolvido para a Vinheria Agnello tem como objetivo monitorar as 3 principais condições do ambiente onde os vinhos são armazenados. Este sistema visa garantir que os requisitos ja apresentados estejam sempre dentro dos limites recomendados para preservar a qualidade do vinho. 

## ♦ Funcionalidade
- O sistema utiliza um sensor LDR para capturar os dados de luminosidade do ambiente.
- Dependendo da intensidade da luz medida, um sistema de alarme visual é acionado:
  - LED verde: luminosidade dentro dos parâmetros ideais (OK).
  - LED amarelo: luminosidade em níveis de alerta.
  - LED vermelho: luminosidade fora dos limites estipulados (problema).
- Caso a luminosidade atinja níveis de alerta, um buzzer será ativado. O buzzer continuará soando enquanto os níveis de luminosidade permanecerem fora da faixa ideal.

- O sistema uliliza uma tela LCD 16x2 I2C para mostrar informacoes: 
  - Temp. Alta: temperatura acima do limite.
  - Temp. baixa: temperatura a baixo do limite.
  - Umidade ok: Niveis de umidade controlados.
  - Umidade alta: Umidade fora dos limites estipuilados.
  - Umidade baixa: Umidade a baixo do limite estipulado.
  - Ambiente escuro: luminosidade dentro dos parâmetros (LED verde). 
  - Ambiente meia-luz: Luminosidade em alerta (LED amarelo).
  - Ambiente claro: luminosidade fora dos limites estipulados (LED vermelho).

- O sistema dispoe de um sensor DHT11 para capturar os dados de temperatura e umidade do ambiente:
  - O DHT11 utiliza um medidor capacitivo para medir a umidade e um termistor para medir a temperatura.
- Caso umidade e temperatura atinjam níveis de alerta, o buzzer será ativado. O buzzer continuará soando enquanto os niveis apresentados permanecam fora da faixa ideal.


## ♦ Dependências
Este projeto utiliza os seguintes componentes e bibliotecas:
- **Arduino Uno** ou qualquer outro modelo de Arduino compatível.
- **Sensor LDR** (Light Dependent Resistor) para medição da luminosidade.
- **LEDs** (verde, amarelo e vermelho) para sinalização do status do ambiente.
- **Buzzer** para alerta sonoro em caso de luminosidade em nível de alerta.
- **Resistor de 10kΩ** para configurar o divisor de tensão com o LDR.
- **Biblioteca Arduino IDE** para programação e upload do código no Arduino.
- **Adafruit Unified Sensor** facilitar o uso de vários tipos de sensores diferentes em projetos.
- **LiquidCrystal I2C** serve para simplificar a comunicação entre um display LCD e um microcontrolador, como o Arduino, utilizando a interface I2C.
- **Adafruit GFX Library** desenvolvida para controlar displays OLED monocromáticos baseados em drives SSD1306, com comunicação I2C ou SPI.
- **Adafruit SSD1306** é um controlador de display OLED (Organic Light-Emitting Diode) que permite exibir informação em dispositivos eletrónicos, como placas Arduino ou ESP32.
- **DHT sensor library** facilita a leitura dos dados de temperatura e humidade de sensores DHT11, DHT22 e AM2302.

## ♦ Como Reproduzir o Projeto

### 1. Materiais Necessários:
- 1x Arduino Uno
- 1x Protoboard 
- 20x Jumpers
- 1x LDR (Light Dependent Resistor)
- 4x Resistor de 1kΩ
- 3x LEDs (verde, amarelo e vermelho)
- 1x Buzzer
- 1x LCD 16x2 I2C 
- 1x DHT11

### 2. Montagem do Circuito:
1. Conecte o barramento positivo da protoboard ao 5V do Arduino.
2. Conecte o barramento negativo da protoboard ao GND do Arduino.
3. Conecte o LED vermelho no pino digital 13 do Arduino.
4. Conecte o LED amarelo no pino digital 12 do Arduino.
5. Conecte o LED verde no pino digital 11 do Arduino.
6. Coloque um resistor entre o terminal positivo de cada LED e o fio que vai para o pino do Arduino.
7. Ligue o terminal positivo do buzzer no pino digital 9 do Arduino e o terminal negativo no GND.
8. Um lado do LDR conecta ao 5V do Arduino e o outro lado do LDR conecta ao pino analógico A5.
9. Entre o pino A5 e o GND, adicione um resistor de 10kΩ.
10. Conecte o pino VCC do módulo I2C do display LCD ao barramento positivo da protoboard.
11. Conecte o pino GND do módulo I2C ao barramento negativo da protoboard.
12. Conecte o pino SDA do módulo I2C ao pino analógico A4 do Arduino.
13. Conecte o pino SCL do módulo I2C ao pino analógico A5 do Arduino.
14. Conecte o pino VCC do sensor DHT11 ao barramento positivo da protoboard.
15. Conecte o pino GND do sensor DHT11 ao barramento negativo da protoboard.
16. Conecte o pino de sinal (DATA) do DHT11 ao pino digital 7 do Arduino.
17. Coloque um resistor de 10kΩ entre o pino de sinal do DHT11 e o barramento positivo (pull-up).
18. Conecte o pino VCC do sensor de gás (MQ) ao barramento positivo da protoboard.
19. Conecte o pino GND do sensor de gás ao barramento negativo da protoboard.
20. Conecte o pino AOUT (saída analógica) do sensor de gás ao pino analógico A1 do Arduino.
21. Verifique se todas as conexões estão firmes e corretas.
22. Conecte o Arduino ao computador via cabo USB para alimentar o circuito e realizar o upload do código.


### 3. Como Rodar o Código:
1. Conecte o Arduino ao computador e abra a IDE do Arduino.
2. Selecione o modelo correto do Arduino na IDE e a porta COM.
3. Instale as bibliotecas necessárias para o funcionamento do programa. 
4. Insira o codigo para a IDE e faça o upload para o seu Arduino.
5. Observe o comportamento dos LEDs e do buzzer conforme a luminosidade medida pelo LDR.


## ♦ Representação do projeto

<img 
    align="center" 
    alt="Sistema de Monitoramento" 
    title="Sistema de Monitoramento"
    width="600px" 
    style="padding-right: 10px;" 
    src="https://media.discordapp.net/attachments/1355162952348602390/1373053064876916817/image.png?ex=682902d0&is=6827b150&hm=2e91736ea4704a01cebcf281b13e1df1ccff85d3f0f27a3af20085731d53ddc9&=&format=webp&quality=lossless&width=1865&height=1168"
/>

## Nome Integrantes e RM

Guilherme de Araújo Moreira - RM: 561848

Camila de Mendonça da Silva - RM: 565491

Arthur de Sousa Pereira - RM: 561380

Yan Breno Barutti Conceição - RM: 566412

### 💻 Tecnologias utilizadas

<img 
    align="left" 
    alt="C++"
    title="C++" 
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" 
/>
<img 
    align="left" 
    alt="ARDUINO IDE" 
    title="ARDUINO IDE"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original-wordmark.svg" 
/>
<img 
    align="left" 
    alt="GIT" 
    title="GIT"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" 
/>
<img 
    align="left" 
    alt="GITHUB" 
    title="GITHUB"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original-wordmark.svg" 
/>

<br>

## ♦ Links do projeto:

- 🔗 **[Simulação no Tinkercad]  <- LINKS AQUI ->  **
- 🎥 **[Vídeo explicativo]  <- LINKS AQUI ->  **
